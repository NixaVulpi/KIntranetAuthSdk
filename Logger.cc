#include <QtCore/QtGlobal>
#include <QtCore/QString>
#include <QtCore/QDateTime>
#include <QtCore/QMutex>
#include <QtCore/QCoreApplication>
#include <Windows.h>
#include "Logger.h"

Logger& Logger::instance() {
    static Logger logger;
    return logger;
}

Logger::Writer Logger::writer() {
    return Writer(this);
}

Logger::Writer::Writer(Logger* logger) : m_logger(logger), m_buffer(QStringLiteral("")), m_textStream(&m_buffer, QIODevice::WriteOnly), m_dateTimeFormat(QStringLiteral("yyyy-MM-dd hh:mm:ss.zzz")) {
    m_textStream <<
        "[" << QDateTime::currentDateTime().toString(m_dateTimeFormat) <<
        "] [" << QString::number(QCoreApplication::applicationPid(), 16).toUpper().rightJustified(8, '0') <<
        "] ";
}

Logger::Writer::~Writer() {
    m_textStream.flush();
    if (!m_buffer.endsWith('\n')) {
        m_buffer.append("\r\n");
    }
    QMutexLocker locker(&m_logger->m_mutex);
    write(m_buffer);
}

QTextStream& Logger::Writer::stream() {
    return m_textStream;
}

void Logger::Writer::write(const QString& message) {
    OutputDebugStringW(reinterpret_cast<const wchar_t*>(message.utf16()));
}

#pragma once

#include <QtCore/QTextStream>
#include <QtCore/QString>
#include <QtCore/QMutex>

class Logger {
public:
    static Logger& instance();

    class Writer {
    public:
        Writer(Logger* logger);
        Writer(const Writer&) = delete;
        Writer(Writer&&) = delete;
        ~Writer();
        Writer& operator=(const Writer&) = delete;
        Writer& operator=(Writer&&) = delete;
        QTextStream& stream();

    private:
        static void write(const QString& message);

        Logger* m_logger;
        QString m_buffer;
        QTextStream m_textStream;
        QString m_dateTimeFormat;
    };

    Writer writer();

private:
    QMutex m_mutex;
};

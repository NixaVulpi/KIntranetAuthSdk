#include <cstdint>
#include "Logger.h"
#include "Krt.h"
#include "KIntranetAuthSdk.h"
#include "KIntranetAuthorize.h"

static const QString _allFeatures[] = {
    QStringLiteral("excel_split_merge"),
    QStringLiteral("screen_recording"),
    QStringLiteral("split_merge_tool"),
    QStringLiteral("pdf_split"),
    QStringLiteral("pdf_merge"),
    QStringLiteral("doc_lose_weight"),
    QStringLiteral("img_loss_compress"),
    QStringLiteral("ocr"),
    QStringLiteral("et_filter"),
    QStringLiteral("data_comparison"),
    QStringLiteral("gbbasicfunction"),
    QStringLiteral("gbofficialfunction"),
    QStringLiteral("gbofficialprintfunction"),
    QStringLiteral("gjbbasicfunction"),
    QStringLiteral("gjbofficialfunction"),
    QStringLiteral("pdf2doc"),
    QStringLiteral("pdf_2doc"),
    QStringLiteral("pdf_2doc_local"),
    QStringLiteral("pdf_2et_local"),
    QStringLiteral("pdf_2ppt_local"),
    QStringLiteral("pdf_split_local"),
    QStringLiteral("pdf_merge_local"),
    QStringLiteral("pdf_2cad_local"),
    QStringLiteral("pdf_2cad"),
    QStringLiteral("cad_2pdf_local"),
    QStringLiteral("cad_2pdf"),
    QStringLiteral("pdf_2txt_local"),
    QStringLiteral("pdf_2txt"),
    QStringLiteral("pdf_2img_pdf_local"),
    QStringLiteral("pdf_2img_pdf"),
    QStringLiteral("pdf_caj2pdf_local"),
    QStringLiteral("pdf_caj2pdf"),
    QStringLiteral("pic_2pdf_local"),
    QStringLiteral("pic_2pdf"),
    QStringLiteral("pdf_edit"),
    QStringLiteral("pdf_text_edit"),
    QStringLiteral("pdf_pic_edit"),
    QStringLiteral("pdf_img_extract"),
    QStringLiteral("pdf_compress"),
    QStringLiteral("pdf_cover_pen"),
    QStringLiteral("pdf_num_edit"),
    QStringLiteral("pdf_page_edit"),
    QStringLiteral("pdf_page_move"),
    QStringLiteral("pdf_pagehf_edit"),
    QStringLiteral("pdf_watermark_edit"),
    QStringLiteral("pdf_batch_output"),
    QStringLiteral("pdf_sign"),
    QStringLiteral("pdf_page_extract"),
    QStringLiteral("pdf_page_output"),
    QStringLiteral("pdf_ocr"),
    QStringLiteral("pdf_background"),
    QStringLiteral("pdf_link"),
    QStringLiteral("pdf_annex"),
    QStringLiteral("pdf_page_copy"),
    QStringLiteral("pdf_page_split"),
    QStringLiteral("pdf_page_crop"),
    QStringLiteral("pdf_table_extract"),
    QStringLiteral("pdf_scan_edit"),
    QStringLiteral("pdf_scan_optimize"),
    QStringLiteral("pdf_batch_adddelwm"),
    QStringLiteral("pdf_edit_path"),
    QStringLiteral("pdf_videoedit"),
    QStringLiteral("pdf_audioedit"),
    QStringLiteral("pdf_videosave"),
    QStringLiteral("pdf_audiosave"),
    QStringLiteral("pdf_page_replace"),
    QStringLiteral("pdf_page_size"),
    QStringLiteral("pdf_password"),
    QStringLiteral("pdf_2html"),
    QStringLiteral("pdf_page_manage"),
    QStringLiteral("pdf_2doc_bypage_local"),
    QStringLiteral("pdf_2et_bypage_local"),
    QStringLiteral("pdf_2ppt_bypage_local"),
    QStringLiteral("pdf_annotate"),
    QStringLiteral("pdf_annotation"),
    QStringLiteral("pdf_output_annotate"),
    QStringLiteral("pdf_watermark"),
    QStringLiteral("pdf_txt_extract"),
    QStringLiteral("pure_image_pdf"),
    QStringLiteral("output_highlight"),
    QStringLiteral("pdf_watermark_output"),
    QStringLiteral("pdf_new"),
    QStringLiteral("pdf_encryption"),
    QStringLiteral("pdf_virtualprint"),
    QStringLiteral("table_extract"),
    QStringLiteral("pdf_invoiceprint"),
    QStringLiteral("pdf_formedit"),
    QStringLiteral("pdf_gencatalogue"),
    QStringLiteral("pdf_genbookmark"),
    QStringLiteral("pdf_delete_blankpage"),
    QStringLiteral("pdf_identifyform"),
    QStringLiteral("pdf_reverseorder"),
    QStringLiteral("img_output"),
    QStringLiteral("screenshot"),
    QStringLiteral("advanced_print"),
    QStringLiteral("doc_check"),
    QStringLiteral("mul_print"),
    QStringLiteral("pdf_2doc_bypage"),
    QStringLiteral("pdf_2et"),
    QStringLiteral("pdf_2et_bypage"),
    QStringLiteral("pdf_2ppt"),
    QStringLiteral("pdf_2ppt_bypage"),
    QStringLiteral("delete_blankpage"),
    QStringLiteral("file_backup"),
    QStringLiteral("background")
};

void GetSNPrivileges(QList<QString>& outList) {
    Logger::instance().writer().stream() << "[AuthBypass] GetSNPrivileges() called";

    for (const QString& feature : _allFeatures) {
        outList.append(feature);
    }
}

IKIntranetAuthorize& _kintranetauthsdk_GetAuthObject() {
    Logger::instance().writer().stream() << "[AuthBypass] GetAuthObject() called";

    //bool enterprise = krt::product::isEnterprise();
    //Logger::instance().writer().stream() << "[AuthBypass] IsEnterprise = " << (enterprise ? "true" : "false");

    //bool pdfStandalone = krt::product::IsPDFStandAloneVersion();
    //Logger::instance().writer().stream() << "[AuthBypass] IsPDFStandAloneVersion = " << (pdfStandalone ? "true" : "false");

    //if (enterprise && pdfStandalone) {
    //    static KIntranetAuthorizePdf instancePdf;
    //    return instancePdf;
    //}

    static KIntranetAuthorize instance;
    return instance;
}

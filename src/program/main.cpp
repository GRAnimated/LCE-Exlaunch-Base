#include "ExceptionHandler.h"
#include "lib.hpp"
#include "logger/Logger.hpp"
#include "Graphics/TextWriter.h"

#include "Minecraft.Client/Minecraft.h"

static const char* DBG_FONT_PATH = "DebugData/Font/nvn_font_jis1.ntx";
static const char* DBG_SHADER_PATH = "DebugData/Font/nvn_font_shader_jis1.bin";
static const char* DBG_TBL_PATH = "DebugData/Font/nvn_font_jis1_tbl.bin";

HOOK_DEFINE_TRAMPOLINE(GuiRenderHook) {
    static void Callback(void *gui) {
        Orig(gui);
        Logger::log("GuiRenderHook!");

        TextWriter::renderSetup();
        TextWriter::DisplayText(Minecraft::GetInstance()->mDefaultFont, L"Hello World!", 50, 20, 20, 0xFFFFFFFF, true);
    }
};

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    exl::hook::Initialize();

    //nn::os::SetUserExceptionHandler(exception_handler, nullptr, 0, nullptr);
    //installExceptionStub();

    Logger::instance().init(LOGGER_IP, 3080);
    Logger::log("Logger inited!");

    GuiRenderHook::InstallAtOffset(0x69CF5C);
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}
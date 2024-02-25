#pragma once

#include "Minecraft.Client/gui/Font.h"
#include "Minecraft.Client/renderer/GlStateManager.h"
#include <string>

class TextWriter {
    public:
    static void renderSetup(bool disableTex = true) {
        GlStateManager::matrixMode(1);
        GlStateManager::loadIdentity();
        GlStateManager::ortho(0.0f, 640, 360, 0.0f, -1.0f, 3000.0f);
        GlStateManager::matrixMode(0);
        GlStateManager::loadIdentity();
        GlStateManager::translatef(0.0f, 0.0f, 0.0f);
        GlStateManager::scalef(1.0f, 1.0f, 1.0f);
        GlStateManager::disableCull();
        GlStateManager::disableLighting();
        GlStateManager::disableDepthTest();
        if (disableTex) GlStateManager::disableTexture();
        else            GlStateManager::enableTexture();
        GlStateManager::enableBlend();
        GlStateManager::blendFunc(4, 5);
        GlStateManager::color4f(1, 1, 1, 1);
        GlStateManager::disableFog();
    }

    static void DisplayText(Font* font, const std::wstring& text, float size, float x, float y, uint32_t color = 0xFFFFFFFF, bool normal = true) {
        GlStateManager::enableTexture();
        GlStateManager::pushMatrix();
        GlStateManager::translatef(x, y, 0);
        GlStateManager::scalef(size, size, 0);
        if (normal)  font->drawShadow(text, 0, 0, color);
        else         font->draw      (text, 0, 0, color, 0, 0);
        GlStateManager::popMatrix();
    }
};
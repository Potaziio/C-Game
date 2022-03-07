#include "color.h"

NormColor ColorToNorm(Color color) {
    return (NormColor){ color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f };
}


Color NormColorToColor(NormColor color) {
    return (Color){ color.r * 255.0f, color.b * 255.0f, color.g * 255.0f, color.a * 255.0f };
}

Color RandomColor() {
    return (Color){
        randFloat(0.0f, 255.0f), 
        randFloat(0.0f, 255.0f),
        randFloat(0.0f, 255.0f),
        randFloat(0.0f, 255.0f)};
}

NormColor RandomNormColor() {
    return (NormColor) {
        RGBANORM(
                randFloat(0.0f, 255.0f), 
                randFloat(0.0f, 255.0f),
                randFloat(0.0f, 255.0f),
                randFloat(0.0f, 255.0f))};
}

#include <Texture.h>

void Texture2D::SetSize(int x, int y) {
    _Size.w = x;
    _Size.h = y;
    _Dest.w = x;
    _Dest.h = y;
}

void Texture2D::SetPosition(int x, int y) {
    _Dest.x = x;
    _Dest.y = y;
}
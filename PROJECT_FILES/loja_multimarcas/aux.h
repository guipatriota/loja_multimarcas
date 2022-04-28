#pragma once
#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED

int cls()
{   // limpa a tela no windows, do jeito oficial
    CONSOLE_SCREEN_BUFFER_INFO      info;
    HANDLE      H = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD       origem = { 0,0 };
    DWORD         total;
    if (H == INVALID_HANDLE_VALUE) return -1;
    GetConsoleScreenBufferInfo(H, &info);
    int r = FillConsoleOutputCharacter(H, (TCHAR)' ',
        info.dwSize.X * info.dwSize.Y,
        origem, &total);
    int s = FillConsoleOutputAttribute(
        H, info.wAttributes,
        info.dwSize.X * info.dwSize.Y,
        origem, &total);
    SetConsoleCursorPosition(H, origem);
    return 0;
};  // end cls()

#endif
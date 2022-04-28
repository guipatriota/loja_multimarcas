#pragma once
#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

#ifndef quantidadedeprodutos
#define quantidadedeprodutos 6
#endif
char* marca[quantidadedeprodutos] =
{
"Toyota    ",
"VW        ",
"Tesla     ",
"Chevrolet ",
"Ford      ",
"Tesla     "
};
char* modelo[quantidadedeprodutos] =
{
"Prius     ",
"Gol       ",
"Model-X   ",
"Opala     ",
"Maverick  ",
"Model-Y   "
};

double valor[quantidadedeprodutos] = { 110000.00, 105999.99, 310500.00, 125060.60, 120000.00, 280000.00 };

int   pedido[quantidadedeprodutos] = { 0, 0, 0, 0, 0, 0 };

#endif DADOS_H_INCLUDED
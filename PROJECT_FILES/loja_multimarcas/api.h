#pragma once
#ifndef API_H_INCLUDED
#define API_H_INCLUDED

/*! \file api.h
 *  \brief Arquivo header em C para conexão com banco de dados MySQL.
 *
 *  Neste arquivo você deverá criar ao menos as seguintes funções:
 *      - contarCarros()    -> retorna um int com a quantidade de carros cadastrados no banco de dados
 *      - marcas()          -> retorna um vetor de ponteiros char com os nomes das marcas dos carros, na mesma ordem dos IDs.
 *      - modelos()         -> retorna um vetor de ponteiros char com os nomes dos modelos dos carros, na mesma ordem dos IDs.
 *      - valores()         -> retorna um vetor de ponteiros double com os valores dos carros, na mesma ordem dos IDs.
 *
 */
int contarCarros(void)
{   // Colocar código para contar a quantidade de carros cadastrados no banco de dados
    return 6;
};  // end ler()

/*void marcas(char* marca, int quantidadedeprodutos) {
    char * marca_temp[6] = {"Toyota    ", "VW        ", "Tesla     ", "Chevrolet ", "Ford      ", "Tesla     "};
    int i = 0;
    for (i = 0; i < quantidadedeprodutos; i++) {
        marca[i] = marca_temp[i];
    }

    return;
};
*/
#endif
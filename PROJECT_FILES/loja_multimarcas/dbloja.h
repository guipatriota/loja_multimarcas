#pragma once
#ifndef DBLOJA_H_INCLUDED
#define DBLOJA_H_INCLUDED

#include <mysql.h>
#include <stdlib.h>
#include <stdio.h>
#include "seguro.h"

#define endereco "localhost"
#define usuario "root"
#define nome_db "loja_multimarcas"

void mostra_tabelas() {

    MYSQL * conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    
    char *server = endereco;
    char *user = "root";
    //set the password for mysql server here
    char *password = seguro; /* set me first */
    char *database = nome_db;
    
    conn = mysql_init(NULL);

    /* Connect to database */
    if (!mysql_real_connect(conn, server,
        user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
    }
    
    /* send SQL query */
    if (mysql_query(conn, "show full tables")) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
    }
    
    res = mysql_use_result(conn);
    
    /* output table name */
    printf("MySQL Tables in mysql database:\n");
    while ((row = mysql_fetch_row(res)) != NULL)
      printf("%s\t\t|\t%s \n", row[0], row[1]);
    
    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);

}

void mostra_carros() {

    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    char* server = endereco;
    char* user = "root";
    //set the password for mysql server here
    char* password = seguro; /* set me first */
    char* database = nome_db;

    conn = mysql_init(NULL);

    /* Connect to database */
    if (!mysql_real_connect(conn, server,
        user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    /* send SQL query */
    if (mysql_query(conn, "select * from carro;")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);

    /* output table name */
    printf("MySQL Tables in mysql database:\n\n");
    printf("Modelo\t\t|\tFabricante\t|\tCombustível\t|\tCor \n");
    while ((row = mysql_fetch_row(res)) != NULL)
        printf_s("%s\t\t|\t%s\t|\t%s\t|\t%s \n", row[1], row[2], row[3], row[4]);

    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);

}

// defina a função de recuperação do número de registros na tabela CARRO:
int busca_quantidade_registros(void) {
	return 4;
}

char* recupera_carros() {

    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    char* server = endereco;
    char* user = "root";
    //set the password for mysql server here
    char* password = seguro; /* set me first */
    char* database = nome_db;

    conn = mysql_init(NULL);

    /* Connect to database */
    if (!mysql_real_connect(conn, server,
        user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    /* send SQL query */
    if (mysql_query(conn, "select * from carro;")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);

    /* output table name */
    printf("MySQL Tables in mysql database:\n\n");
    printf("Modelo\t\t|\tFabricante\t|\tCombustível\t|\tCor \n");
    while ((row = mysql_fetch_row(res)) != NULL)
        printf_s("%s\t\t|\t%s\t|\t%s\t|\t%s \n", row[1], row[2], row[3], row[4]);

    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);
    //char *a = "a";
    //return a;
}

char* marca[] =
{
"Toyota    ",
"VW        ",
"Tesla     ",
"Chevrolet ",
"Ford      ",
"Tesla     "
};

char* modelo[] =
{
"Prius     ",
"Gol       ",
"Model-X   ",
"Opala     ",
"Maverick  ",
"Model-Y   "
};

double valor[] = { 110000.00, 105999.99, 310500.00, 125060.60, 120000.00, 280000.00 };

//int   pedido[] = { 0, 0, 0, 0, 0, 0 };

// Crie a função para recuperar a lista de marcas, modelos e valores:


// Buscar do banco a quantidade de registros em CARRO e retornar este valor:


#endif
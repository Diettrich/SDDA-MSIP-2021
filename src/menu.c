//
//  menu.c
//  SDDA-MSIP
//
//  Created by Zougrar Anouar on 3/6/21.
//  Copyright © 2021 Zougrar Anouar. All rights reserved.
//

#include "../header/menu.h"
#include "../header/contact.h"
#include <stdlib.h>
#include <string.h>


void entrer_menu()
{
    puts("==================================================");
    puts("               Contact téléphonique               ");
    puts("==================================================");
    printf("\nBienvenu entrez:\n\n");
    puts("  1 pour afficher tout vos contactes");
    puts("  2 pour chercher un contacte");
    puts("  3 pour ajouter un contacte");
    puts("  4 pour suprimer un contacte");
    puts("  5 pour aide");
    puts("  exit");
    printf("\n");
}

char *read_line()
{
    printf("> ");
    size_t bufsize = 1024;
    char *line = malloc(bufsize * sizeof(char));
    getline(&line, &bufsize, stdin);
    return line;
}

char *read_name()
{
    printf("entrer nom: ");
    size_t bufsize = 1024;
    char *line = malloc(bufsize * sizeof(char));
    getline(&line, &bufsize, stdin);
    return line;
}

char *read_phone()
{
    printf("entrer numero: ");
    size_t bufsize = 1024;
    char *line = malloc(bufsize * sizeof(char));
    getline(&line, &bufsize, stdin);
    return line;
}

int execute_line(char *line, contact root, contact* temp_ptr)
{
    if (!strcmp(line, "exit\n")) {
        return 0;
    } else if (!strcmp(line, "1\n"))
    {
        show_sorted_tree(root, root);
        return 1;
    } else if (!strcmp(line, "2\n"))
    {
        char *name = read_name();
        name[strlen(name) - 1] = '\0';
        
        if (search_node_by_name(root, temp_ptr, name)) {
            show_sorted_tree((*temp_ptr)->fils, root);
        } else {
            puts("aucune resultat");
        }
        return 1;
    } else if (!strcmp(line, "3\n"))
    {
        char* name = read_name();
        char* phone = read_phone();
        name[strlen(name) - 1] = '\0';
        phone[strlen(phone) - 1] = '\0';
        create_new_contact(root, name, phone);
        return 1;
    } else if (!strcmp(line, "4\n"))
    {
        char *name = read_name();
        name[strlen(name) - 1] = '\0';
        
        if (search_node_by_name(root, temp_ptr, name)) {
            (*temp_ptr)->isEmpty = 1;
            puts("supprimé");
        } else {
            puts("aucune resultat");
        }
        return 1;
        return 1;
    } else if (!strcmp(line, "5\n"))
    {
        puts("  1 pour afficher tout vos contactes");
        puts("  2 pour chercher un contacte");
        puts("  3 pour ajouter un contacte");
        puts("  4 pour suprimer un contacte");
        puts("  5 pour aide");
        puts("  exit");
        printf("\n");
        return 1;
    } else {
        puts("commande invallide");
        return 1;
    }
    return 0;
}

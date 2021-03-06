//
//  main.c
//  SDDA-MSIP
//
//  Created by Zougrar Anouar on 3/5/21.
//  Copyright © 2021 Zougrar Anouar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "header/contact.h"
#include "header/menu.h"

int main(int argc, const char * argv[]) {
    
    contact temp;
    contact* temp_ptr;
    temp_ptr = &temp;
    int on_loop = 1;
    
    // contact CONTACT_ARRAY[10000];
    
    contact root = (contact)malloc(sizeof(contact));
    
    // contact a = (contact)malloc(sizeof(contact));
    // contact b = (contact)malloc(sizeof(contact));
    
    // create_contact_node(a, 'a', "0659806122");
    // create_contact_node(b, 'b', "0659806159");
    
    // a->frere = b;
    root->fils = NULL;
    root->frere = NULL;
    root->isEmpty = 1;
    
    // add_node(a, temp_ptr, 'd');
    // add_node(root, temp_ptr, 'z');
    // add_node(root, temp_ptr, 's');
    
    create_new_contact(root, "anouar", "0633228877");
    create_new_contact(root, "asmae", "0633228877");
    create_new_contact(root, "jacob", "0633228877");
    create_new_contact(root, "royal", "0633228877");
    create_new_contact(root, "adec", "0633228877");
    create_new_contact(root, "crsv", "0633228877");
    create_new_contact(root, "zoran", "0633228877");
    create_new_contact(root, "chochi", "0633228877");
    create_new_contact(root, "wakaza", "0633228877");
    
    entrer_menu();
    
    do {
        char* line = read_line();
        puts("==>");
        on_loop = execute_line(line, root, temp_ptr);
    } while (on_loop == 1);
    
    

//    printf("--- test:\n\n");
//    show_sorted_tree(root, root);
//    delete_contact(root, "jacob");
//    puts("-----------");
//    show_sorted_tree(root, root);
//    int xx = search_node_by_name(root, temp_ptr, "adec");
//    printf("%d\n", xx);
//    printf("%c\n", (*temp_ptr)->caractere);
    // printf("contact created -- char: %c --- telephone: %s\n", root->fils->caractere, root->fils->telephone);
    // printf("contact created -- char: %c --- telephone: %s\n", a->frere->caractere, a->frere->telephone);
    return 0;
}

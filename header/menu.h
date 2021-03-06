//
//  menu.h
//  SDDA-MSIP
//
//  Created by Zougrar Anouar on 3/6/21.
//  Copyright © 2021 Zougrar Anouar. All rights reserved.
//

#ifndef menu_h
#define menu_h

#include <stdio.h>
#include "contact.h"

void entrer_menu(void);
char *read_line(void);
int execute_line(char*, contact, contact*);

#endif /* menu_h */

/*
 * main.c
 * Using the singly linked list implementation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


static inline void fflush_stdin() {
    char c;
    do {
        c = getchar();
    } while((c != '\n') && (c != EOF));
}

static char* Fgets(char *s, size_t len, FILE* f) {
    char *ret = fgets(s, len, stdin);
    s[strlen(s)-1] = '\0';
    return ret;
}

/* A sample object type to be stored in the linked list.    */
typedef struct guitar {
    unsigned int product_id_;
    char *manufacturer_, *model_name_;
    double price_;
    unsigned short strings_, frets_;
} Guitar;

/*  Functions to manipulate Guitar  */
int userInput(Guitar *g);
int setValues(Guitar *g, unsigned int p_id, char *man, char *model, double pr, unsigned short strings, unsigned short frets);
void clearValues(Guitar *g);
void print_info(Guitar *g);

/*  main program    */
int main(int argc, char *argv[]) {
    S_List mylist;
    init_head(&mylist);
    
    Guitar myGuitar;
    memset(&myGuitar, '\0', sizeof(Guitar));
    size_t size = sizeof(Guitar);
    
    int n;
    printf("Number of inputs: ");
    scanf("%d", &n);
    
    /* Fill up the list */
    for(int i = 1; i <= n; i++) {
        userInput(&myGuitar);
        push(&mylist, (void*)&myGuitar, size);
    }
    
    /* Display list contents    */
    printf("%10s %15s %15s %12s %7s %5s\n", "PRODUCT ID", "MANUFACTURER", "MODEL NAME", "PRICE", "STRINGS", "FRETS");
    print_list_cb(print_info, &mylist);
    
	return 0;
}

int userInput(Guitar *g) {
    char manuf[128]="", model[128]="";
    unsigned int p_id;
    unsigned short strings, frets;
    double price;
    
    clearValues(g);
    
    printf("Product Id: ");
    //fflush_stdin();
    scanf("%u", &p_id);
    
    printf("Manufacturer: ");
    fflush_stdin();
    Fgets(manuf, 128, stdin);
    
    fflush_stdin();
    printf("Model Name: ");
    Fgets(model, 128, stdin);
    
    printf("Price: ");
    //fflush_stdin();
    scanf("%lf", &price);
    
    printf("No. of strings: ");
    //fflush_stdin();
    scanf("%u", &strings);
    
    printf("Frets: ");
    //fflush_stdin();
    scanf("%u", &frets);
    
    return setValues(g, p_id, manuf, model, price, strings, frets);
}

int setValues(Guitar *g, unsigned int p_id, char *man, char *model, double pr, unsigned short strings, unsigned short frets) {
    g->product_id_ = p_id;
    g->price_ = pr;
    g->strings_ = strings;
    g->frets_ = frets;
    
    // Do malloc() if not done already 
    if(!g->manufacturer_) {
        if(!(g->manufacturer_ = malloc(strlen(man) + 1)))
            return -1;
    }
    if(!g->model_name_) {
        if(!(g->model_name_ = malloc(strlen(model) +1)))
            return -1;
    }
    strcpy(g->manufacturer_, man);
    strcpy(g->model_name_, model);
    return 0;
}

void clearValues(Guitar *g) {
    memset(g, '\0', sizeof(Guitar));
}

void print_info(Guitar *g) {
    printf("%10u %15s %15s %10.2lf %7u %5u\n",                                    \
            g->product_id_, ((g->manufacturer_) ? g->manufacturer_ : "null"),   \
            ((g->model_name_) ? g->model_name_ : "null"),                       \
            g->price_, g->strings_, g->frets_                                   \
          );
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum TYPE {
    WEAPON,
    SHIELD,
    ARMOR,
    BOOK,
    OTHER
};

typedef struct ItemCore {
    char *name;
    float value;
    enum TYPE type;
} ItemCore;

ItemCore* makeItemCore(char *name, float value, enum TYPE type) {
    ItemCore *ic = NULL;
    ic = (ItemCore *) malloc(sizeof(ItemCore));
    if (ic == NULL) {
        printf("Allocation of Itemcore failed!\n");
        return NULL;
    } else {
        ic->name = malloc(sizeof(name));
        strcpy(ic->name, name);
        ic->value = value;
        ic->type = type;
        return ic;
    }
}

typedef struct Weapon {
    ItemCore *itemcore;
    float atk;
} Weapon;

typedef struct Book {
    ItemCore *itemcore;
    char *content;
} Book;

typedef struct MiscItem {
    ItemCore *itemcore;
    char *description;
    float x;
} MiscItem;

Book* makeBook(char *name, float value, enum TYPE type, char *content) {
    Book *b = NULL;
    b = (Book*) malloc(sizeof(Book));
    if (b == NULL) {
        printf("Allocation of Book failed\n");
        return NULL;
    } else {
        ItemCore *ic = makeItemCore(NULL, value, type);
        strcpy(ic->name, name);
        b->itemcore = ic;
        strcpy(b->content, content);
        return b;
    }
}

Weapon* makeWeapon(char *name, float value, enum TYPE type, float atk) {
    printf("Creating w\n");
    Weapon *w = NULL;
    w = (Weapon*) malloc(sizeof(Weapon));
    if (w == NULL) {
        printf("Allocation of Weapon failed\n");
        return NULL;
    } else {
        printf("Making itemcore\n");
        ItemCore *ic = makeItemCore(name, value, type);
        w->itemcore = ic;
        w->atk = atk;
        printf("Returning w\n");
        return w;
    }
}

void deleteItemCore(ItemCore *ic) {
    printf("Deleting ic name\n");
    free(ic->name);
    printf("Deleting ic\n");
    free(ic);
    ic = NULL;
}

void deleteWeapon(Weapon *w) {
    printf("Deleting ic of Weapon\n");
    deleteItemCore(w->itemcore);
    printf("Deleting weapon\n");
    free(w);
    w = NULL;
}

int main() {
    Weapon *w = makeWeapon("Exkackibur", 10000, WEAPON, 666);
    printf("Printing w\n");
    printf("%s hat %f Angriff\n", w->itemcore->name, w->atk);
    deleteWeapon(w);

}

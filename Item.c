#include <stdlib.h>
#include <stdio.h>

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
        ic->name = name;
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
    Weapon *w = NULL;
    w = (Weapon*) malloc(sizeof(Weapon));
    if (w == NULL) {
        printf("Allocation of Weapon failed\n");
        return NULL;
    } else {
        ItemCore *ic = makeItemCore(NULL, value, type);
        strcpy(ic->name, name);
        w->itemcore = ic;
        w->atk = atk;
        return w;
    }
}

void deleteItemCore(ItemCore *ic) {
    free(ic);
    ic = NULL;
}

void deleteWeapon(Weapon *w) {
    deleteItemCore(w->itemcore);
    free(w);
    w = NULL;
}

int main() {
}

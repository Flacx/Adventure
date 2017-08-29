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

Weapon* makeWeapon(char *name, float value, enum TYPE type, float atk) {
    Weapon *w = NULL;
    w = (Weapon*) malloc(sizeof(Weapon));
    if (w == NULL) {
        printf("Allocation of Weapon failed\n");
        return NULL;
    } else {
        ItemCore *ic = makeItemCore(name, value, type);
        w->itemcore = ic;
        w->atk = atk;
        return w;
    }
}

int main() {
}

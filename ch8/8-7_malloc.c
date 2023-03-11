
typedef long Align;

union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
};

typedef union header Header;

 typedef struct {           /* _person がタグ名 */
    char name[20];        /* 文字配列型のメンバ name */
    char sex;              /* 文字型メンバ sex */
    int age;               /* 整数型メンバ age */
    double height;         /* 倍精度実数型メンバ height */
    double weight;         /* 倍精度実数型メンバ weight */
} person_t;

int main(int argc, char *argv[]) {
    person_t p = {"Tom", 'M', 19, 175.2, 69.5};
//   person_t p = {"Tom", 'M', 19, 175.2, 69.5};
   printf("%p", p);
}
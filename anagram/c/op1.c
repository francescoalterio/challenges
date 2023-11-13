#include <stdio.h>

int str_length(char *str);
int str_comp(char *first_str, char *second_str);
void str_sort(char str[], int length);
void to_lower_case(char str[]);

int anagram(char first_word[], char second_word[])
{
    int first_word_length = str_length(first_word);
    int second_word_length = str_length(second_word);

    to_lower_case(first_word);
    to_lower_case(second_word);

    printf("%s\n", first_word);
    if ((first_word_length != second_word_length) || (str_comp(first_word, second_word)))
    {
        return 0;
    }

    str_sort(first_word, first_word_length);
    str_sort(second_word, second_word_length);

    return str_comp(first_word, second_word);
}

int str_length(char *str)
{
    int length;
    for (length = 0; *str != '\0'; length++, str++)
        ;

    return length;
}

int str_comp(char *first_str, char *second_str)
{
    int i;
    for (; *first_str == *second_str; first_str++, second_str++)
    {
        if (*first_str == '\0' && *second_str == '\0')
            return 1;
    }
    return 0;
}

void str_sort(char str[], int length)
{
    for (int gap = length / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < length; i++)
        {
            if (str[i - gap] > str[i])
            {
                char temp = str[i - gap];
                str[i - gap] = str[i];
                str[i] = temp;
            }
        }
    }
    for (int i = 1; i < length; i++)
    {
        if (str[i - 1] > str[i])
        {
            char temp = str[i - 1];
            str[i - 1] = str[i];
            str[i] = temp;
        }
    }
}

void to_lower_case(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < 97 && str[i] >= 65)
        {
            str[i] += 32;
        }
    }
}

int test(int value, int expect)
{
    printf("EXPECT: %s - RESULT: %s\n", (expect) ? "True" : "False", (value) ? "True" : "False");
}

int main()
{
    char a[] = "AIDE";
    char b[] = "idea";

    char c[] = "aite";
    char d[] = "idea";

    char e[] = "earth";
    char f[] = "heart";

    char g[] = "ape";
    char h[] = "pea";

    char i[] = "hellooo";
    char j[] = "helloo";

    char k[] = "hi";
    char l[] = "hi";

    test(anagram(a, b), 1);
    test(anagram(c, d), 0);
    test(anagram(e, f), 1);
    test(anagram(g, h), 1);
    test(anagram(i, j), 0);
    test(anagram(k, l), 0);
    return 0;
}

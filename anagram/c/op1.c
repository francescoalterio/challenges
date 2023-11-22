#include <stdio.h>
#include <string.h>

int str_length(char *str);
int str_comp(char *first_str, char *second_str);
void str_sort(char str[], int length);
void to_lower_case(char str[]);

int anagram(char *first_word, char *second_word[])
{
    int first_word_length = str_length(first_word);
    int second_word_length = str_length(second_word);

    char first_word_copy[first_word_length];
    char second_word_copy[second_word_length];

    strcpy(first_word_copy, first_word);
    strcpy(second_word_copy, second_word);

    to_lower_case(first_word_copy);
    to_lower_case(second_word_copy);

    printf("%s\n", first_word_copy);
    if ((first_word_length != second_word_length) || (str_comp(first_word_copy, second_word_copy)))
    {
        return 0;
    }

    str_sort(first_word_copy, first_word_length);
    str_sort(second_word_copy, second_word_length);

    return str_comp(first_word_copy, second_word_copy);
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
    test(anagram("AIDE", "idea"), 1);
    test(anagram("aite", "idea"), 0);
    test(anagram("earth", "heart"), 1);
    test(anagram("ape", "pea"), 1);
    test(anagram("hellooo", "helloo"), 0);
    test(anagram("hi", "hi"), 0);
    return 0;
}

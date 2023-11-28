#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

char **find_all_node_modules(char *path, int *node_modules_length);

int main()
{

    printf("Running ModuleKill in this directory...\n");
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    int node_modules_found = 0;
    char **node_modules = find_all_node_modules(cwd, &node_modules_found);
    printf("NODE_MODULES FOUND: %d\n", node_modules_found);
    for (int i = 0; i < node_modules_found; i++)
    {
        free(node_modules[i]);
    }
    free(node_modules);
}

void memory_is_null(void *p)
{
    if (p == NULL)
    {
        printf("ERROR!!\n");
        exit(-1);
    }
}

char **find_all_node_modules(char *path, int *node_modules_length)
{
    int node_modules_found = 0;
    int dir_to_an_length = 0;

    char **dir_to_an = malloc(sizeof(char *));
    memory_is_null(dir_to_an);
    char *firts_path = strdup(path);
    memory_is_null(firts_path);
    dir_to_an[0] = firts_path;
    dir_to_an_length++;

    char **node_modules = malloc(sizeof(char *));
    memory_is_null(node_modules);

    struct dirent *dent;
    DIR *srcdir;

    while (dir_to_an_length > 0)
    {
        char *current_path = strdup(dir_to_an[dir_to_an_length - 1]);
        memory_is_null(current_path);
        free(dir_to_an[dir_to_an_length - 1]);
        dir_to_an = realloc(dir_to_an, (sizeof(char *) * (dir_to_an_length - 1)));
        dir_to_an_length--;
        if (dir_to_an == NULL && dir_to_an_length > 0)
        {
            printf("ERROR!!\n");
            exit(-1);
        }

        srcdir = opendir(current_path);
        if (srcdir == NULL)
        {

            printf("Error -> Could not open directory: %s!!!\n", current_path);
            exit(-1);
        }

        while ((dent = readdir(srcdir)) != NULL)
        {
            struct stat st;

            if (strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0)
            {
                continue;
            }

            char *path_with_dir = calloc(strlen(current_path) + 1 + strlen(dent->d_name) + 1, sizeof(char));
            memory_is_null(path_with_dir);

            strcat(path_with_dir, current_path);
            strcat(path_with_dir, "/");
            strcat(path_with_dir, dent->d_name);

            if (stat(path_with_dir, &st) == 0)
            {
                if (S_ISDIR(st.st_mode))
                {
                    if (strcmp(dent->d_name, "node_modules") == 0)
                    {
                        node_modules[node_modules_found] = strdup(path_with_dir);
                        memory_is_null(node_modules[node_modules_found]);
                        node_modules_found++;
                        printf("%s\n", path_with_dir);
                    }
                    else
                    {
                        dir_to_an = realloc(dir_to_an, sizeof(char *) * (dir_to_an_length + 1));
                        memory_is_null(dir_to_an);
                        dir_to_an[dir_to_an_length] = strdup(path_with_dir);
                        memory_is_null(dir_to_an[dir_to_an_length]);
                        dir_to_an_length++;
                    }
                }
            }
            free(path_with_dir);
        }
        closedir(srcdir);
        free(current_path);
    }

    free(dir_to_an);
    *node_modules_length = node_modules_found;
    return node_modules;
}

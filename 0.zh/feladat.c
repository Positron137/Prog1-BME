#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_node
{
    int door_number;
    char name[50];
    struct s_node *next;
};
typedef struct s_node node;

void print_list(node *list);
node *from_file(char *file_name);
int get_floor_number(node *n);
void booked_per_floor(node *list, int floor_list[8]);
int most_booked_floor(int floor_list[8]);
node *find_by_name(node *list, char name[50]);
void final(char *file_name, char name[50]);

int main(void)
{
    return 0;
}

void print_list(node *list)
{
    node *current = list;
    while (current != NULL)
    {
        printf("A szobaszam: %d, a nev: %s\n", current->door_number, current->name);
        current = current->next;
    }
}

node *from_file(char *file_name)
{
    node *list = NULL;
    FILE *fp = fopen(file_name, "r");
    if (fp != NULL)
    {
        char name[50];
        int door_number;
        while (fscanf(fp, "%d %[^\n]s", &door_number, &name) != EOF)
        {
            node *new_node = malloc(sizeof(node));
            new_node->door_number = door_number;
            strcpy(new_node->name, name);
            new_node->next = list;
            list = new_node;
        }
        fclose(fp);
    }
    else
    {
        printf("Nem sikerult megnyitni a fajlt");
    }
    return list;
}

int get_floor_number(node *n)
{
    int floor_number = (int) ((n->door_number - n->door_number % 100)/100);
    return  floor_number;
}

void booked_per_floor(node *list, int floor_list[8])
{
    for (int i = 0; i < 8; i++)
    {
        floor_list[i] = 0;
    }
    node *current = list;
    while (current != NULL)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == get_floor_number(current))
            {
                floor_list[i]++;
                break;
            }
        }
        current = current->next;
    }
}

int most_booked_floor(int floor_list[8])
{
    int max = 0;
    for (int i = 0; i < 8; i++)
    {
        if (floor_list[i] > max)
        {
            max = floor_list[i];
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (floor_list[i] == max){
            return i;
        }
    }
    return 0;
}

node *find_by_name(node *list, char name[50])
{
    node *current = list;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void final(char *file_name, char name[50])
{
    node *list = from_file(file_name);
    node *current = find_by_name(list, name);
    if (current == NULL)
    {
        printf("Nincs ilyen vendeg");
    } 
    else 
    {
        int floors[8];
        booked_per_floor(list, floors);
        printf("%s %s legzsufoltabb emeleten van\n", current->name, most_booked_floor(floors)==get_floor_number(current)?"a":"nem a");

    }
}
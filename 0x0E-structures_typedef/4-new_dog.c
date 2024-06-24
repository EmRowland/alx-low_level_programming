#include "dog.h"
#include <stdlib.h>

/**
 * _strcpy - copies a string from src to dest
 * @src: source string
 * @dest: destination string
 * 
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
    int i;

    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';

    return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 * 
 * Return: length of the string
 */
int _strlen(char *s)
{
    int i;

    for (i = 0; s[i]; i++)
        ;

    return (i);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * 
 * Return: pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *dog;

    dog = malloc(sizeof(dog_t));
    if (dog == NULL)
        return (NULL);

    dog->name = malloc((_strlen(name) + 1) * sizeof(char));
    if (dog->name == NULL)
    {
        free(dog);
        return (NULL);
    }
    _strcpy(dog->name, name);

    dog->owner = malloc((_strlen(owner) + 1) * sizeof(char));
    if (dog->owner == NULL)
    {
        free(dog->name);
        free(dog);
        return (NULL);
    }
    _strcpy(dog->owner, owner);

    dog->age = age;

    return (dog);
}


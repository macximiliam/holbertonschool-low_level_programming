#ifndef _DOG_H_
#define _DOG_H_

/*
 * Structs, enums and unions definitions
 * Typedefs
 * Function prototypes
 */

/**
 * struct dog - Define a struct representing a dog
 * @name: Pointer to the name of the dog
 * @age: Age of the dog in years
 * @owner: Pointer to the owner's name
 *
 * Description: A structure to store basic information about a dog.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - Typedef for struct dog
 */
typedef struct dog dog_t;

/* Function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* _DOG_H_ */

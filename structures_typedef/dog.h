#ifndef _DOG_H_
#define _DOG_H_

/*
 * Structs, enums and unions definitions
 * Typedefs
 * Function prototypes
 */

/**
* struct dog - Define a new type struct dog
* @name: char * name of the dog
* @age: float age of the dog
* @owner: char * owner of the dog
*
* Description: Longer description
*/
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *, char *, float, char *);

#endif /* _DOG_H_ */

<em> This activity has been created as part of the 42 curriculum by ppodobri. </em>

# Description:
## LIBFT
LIBFT serves as a C Library including a part of glibc aswell as functions from BSD systems, and other functions.

# Instructions:

To compile the library, run make. This creates libft.a at the root of the repository.

```
make        compiles the sources into libft.a
make clean  removes the object files
make fclean removes the object files and libft.a
make re     runs fclean and then all
```

To use it, put libft.a and libft.h next to your own files and include libft.h in them. When compiling, add the archive as an argument, for example:

```
cc main.c libft.a -o program
```

# Resources:

Knowledge was primarily gained through peer review and the classic web search. AI was used for understanding different concepts, primarily pointer logic aswell as for understanding linked lists. No code used was written by AI.

Useful references were the man pages, for example man 3 strlen, cppreference for the C library, and the Norm.

# Detailed Description:
The following Description features the prototype for each function aswell as a description of what the function does.

## Part 1 - Libc Functions

int ft_isalpha(int c);
Checks for an alphabetic character.
Return Value: 1 if an alphabetic character is present, 0 if not.

int ft_isdigit(int c);
Checks for a numeric character.
Return Value: 1 if a numeric character is present, 0 if not.

int ft_isalnum(int c);
Checks for a numeric or alphabetic character.
Return Value: 1 if an alphanumeric character is present, 0 if not.

int ft_isascii(int c);
Checks for characters featured in the ASCII character set.
Return value: 1 if the character is ASCII, 0 if not.

int ft_isprint(int c);
Checks for any printable character including space.
Return value: 1 if the character is printable, 0 if not.

int ft_strlen(const char *s);
Calculates the length of the string pointed to by s excluding '\0'.
Return value: the number of bytes in the string pointed to by s.

void *ft_memset(void *s, int c, size_t n);
Fills the first n bytes of the memory area pointed to by s with the constant byte c.
Return Value: a pointer to the memory area s.

void ft_bzero(void *s, size_t n);
Erases the data in the n bytes of memory pointed to by s by overwriting it with '\0'.
Return Value: none

void *ft_memcpy(void *dest, const void *src, size_t n);
Copies the first n bytes of the memory area pointed to by src into the memory area pointed to by dest. The two areas must not overlap, as the copy is made byte by byte from the start.
Return Value: a pointer to dest.

void *ft_memmove(void *dest, const void *src, size_t n);
Copies the first n bytes of src into dest. The areas may overlap: when dest begins after src, the copy is made from the end so no byte is overwritten before it is read.
Return value: a pointer to dest.

size_t ft_strlcpy(char *dst, const char *src, size_t size);
Copies at most size - 1 bytes of the string pointed to by src into the buffer pointed to by dst, then null-terminates it.
Return Value: The length of the total string it tried to create, that is the length of src.

size_t ft_strlcat(char *dst, const char *src, size_t size);
Appends the string pointed to by src to the end of the string pointed to by dst, never writing more than size bytes in total.
Return Value: The length of the total string it tried to create, that is the initial length of dst plus the length of src.

int ft_toupper(int c);
Convert the lowercase letter to uppercase.
Return Value: The converted letter, or c if the conversion was not possible.

int ft_tolower(int c);
Converts the uppercase letter to lowercase.
Return Value: The converted letter, or c if the conversion was not possible.

int ft_strncmp(const char *s1, const char *s2, size_t n);
Compares at most the first n bytes of the two strings, treating each byte as an unsigned char.
Return Value: a negative number if s1 is smaller, a positive number if s1 is greater, 0 if the compared bytes are equal.

char *ft_strchr(const char *s, int c);
Searches for the first occurrence of the character c in the string pointed to by s. The terminating '\0' is considered part of the string, so searching for it returns a pointer to the end of s.
Return Value: a pointer to the located character, or NULL if the character does not occur.

char *ft_strrchr(const char *s, int c);
Searches for the last occurrence of the character c in the string pointed to by s.
Return Value: a pointer to the located character, or NULL if the character does not occur.

void *ft_memchr(const void *s, int c, size_t n);
Scans the first n bytes of the memory area pointed to by s for the byte c.
Return Value: a pointer to the matching byte, or NULL if it does not occur in the given byte range.

int ft_memcmp(const void *s1, const void *s2, size_t n);
Compares the first n bytes of the memory areas s1 and s2, treating each byte as an unsigned char.
Return Value: a negative number if s1 is smaller, a positive number if s1 is greater, 0 if the compared bytes are equal.

char *ft_strnstr(const char *big, const char *little, size_t len);
Locates the first occurrence of the string little inside the string big, searching at most len characters. If little is empty, big is returned.
Return Value: a pointer to the first character of the match, or NULL if the string is not found.

int ft_atoi(const char *nptr);
Converts the initial portion of the string pointed to by nptr to an int, skipping leading whitespace and applying an optional sign.
Return Value: the converted value.

## Part 2 - Additional Functions

void *ft_calloc(size_t n, size_t size);
Allocates memory for an array of n elements of size bytes each and sets all bytes to '\0'. The multiplication is checked against overflow beforehand.
Return Value: a pointer to the allocated memory, or NULL if the allocation fails.

char *ft_strdup(const char *s);
Allocates memory and copies the string pointed to by s into it.
Return Value: a pointer to the new string, or NULL if the allocation fails.

char *ft_substr(const char *s, unsigned int start, size_t len);
Allocates and returns a copy of the substring of s starting at index start and of at most len characters. If start is past the end of s, an empty string is returned.
Return Value: a pointer to the new substring, or NULL if the allocation fails.

char *ft_strjoin(const char *s1, const char *s2);
Allocates and returns a new string formed by concatenating s1 and s2.
Return Value: a pointer to the new string, or NULL if the allocation fails.

char *ft_strtrim(char const *s1, char const *set);
Trims the characters found in set from both ends of s1, then returns a freshly allocated copy of the remaining characters.
If set is NULL, s1 is duplicated instead.
Return Value: a pointer to the trimmed string, or NULL if the allocation fails.

char **ft_split(const char *s, char c);
Allocates and returns an array of strings obtained by splitting s with the character c used as the delimiter. Each substring is allocated separately and the array is terminated by a NULL pointer.
Return Value: a pointer to the array, or NULL if the allocation fails.

char *ft_itoa(int n);
Allocates and returns the string representation of the integer n, including negative numbers and the smallest int value.
Return Value: a pointer to the new string, or NULL if the allocation fails.

char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
Applies the function f to each character of s, passing its index as the first argument and the character itself as the second, and builds a new string from the results. The input string is not modified.
Return Value: a pointer to the new string, or NULL if the allocation fails.

void ft_striteri(char *s, void (*f)(unsigned int, char*));
Applies the function f to each character of s, passing its index as the first argument and the address of the character itself as the second, so the string can be modified in place.
Return Value: none

void ft_putchar_fd(char c, int fd);
Writes the character c to the given file descriptor.
Return Value: none

void ft_putstr_fd(char *s, int fd);
Writes the string pointed to by s to the given file descriptor.
Return Value: none

void ft_putendl_fd(char *s, int fd);
Writes the string pointed to by s to the given file descriptor, followed by a newline.
Return Value: none

void ft_putnbr_fd(int n, int fd);
Writes the integer n to the given file descriptor in its decimal representation.
Return Value: none

## Part 3 - Linked List

The linked list functions rely on the following structure, declared in libft.h.

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list *ft_lstnew(void *content);
Allocates and returns a new list element, storing the pointer content inside it and setting the next pointer to NULL.
Return Value: a pointer to the new element, or NULL if the allocation fails.

void ft_lstadd_front(t_list **lst, t_list *new);
Adds the element new at the beginning of the list pointed to by lst.
Return Value: none

void ft_lstadd_back(t_list **lst, t_list *new);
Adds the element new at the end of the list pointed to by lst. If the list is empty, new becomes the first element.
Return Value: none

unsigned int ft_lstsize(t_list *lst);
Counts the number of elements in the list.
Return Value: the length of the list.

t_list *ft_lstlast(t_list *lst);
Returns a pointer to the last element of the list.
Return Value: the last element, or NULL if the list is empty.

void ft_lstdelone(t_list *lst, void (*del)(void *));
Frees the content of the element using the function del, then frees the element itself. The next pointer of the element is not followed.
Return Value: none

void ft_lstclear(t_list **lst, void (*del)(void *));
Deletes and frees every element of the list and its content using del, then sets the list pointer to NULL.
Return Value: none

void ft_lstiter(t_list *lst, void (*f)(void *));
Iterates over the list and applies the function f to the content of each element.
Return Value: none

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
Iterates over the list, applies f to the content of each element and builds a new list from the results. If an allocation fails, the new list is cleared with del.
Return Value: a pointer to the new list, or NULL if the allocation fails.
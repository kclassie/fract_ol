/*compare byte string
The memcmp() function compares byte string s1 against byte string s2.
Both strings are assumed to be n bytes long

The memcmp() function returns zero if the two strings are identical, oth-
erwise returns the difference between the first two differing bytes
(treated as unsigned char values, so that `\200' is greater than `\0',
for example). Zero-length strings are always identical. This behavior
is not required by C and portable code should only depend on the sign of
the returned value. */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*fst;
	unsigned char	*sst;

	i = 0;
	if (n == 0)
		return (0);
	if (n != 0)
	{
		fst = (unsigned char *)s1;
		sst = (unsigned char *)s2;
	}
	while (n != 1 && *(fst + i) == *(sst + i))
	{
		i++;
		n--;
	}
	return (*(fst + i) - *(sst + i));
}

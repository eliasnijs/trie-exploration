#ifndef BASE_STRING_H

/* depends on:
 * stdio.h, string.h, base.c, m_arena.c
 * */

/* Strings are a set of chars and the total length. In this file their are
 * several useful functions defined for handling strings.
 *
 * IMPORTANT(Elias): End character token '\0' is considered part of
 * the string. The length of string accounts for this too.
 * */

/* macros */
#define str_lit(c,a,s) str_init(c, ArrayCount(c), a, s)
#define str_prepend(s1, s2, a, s_dest) str_append(s2, s1, a, s_dest);

/* enumerations, structs, unions */
typedef struct string string;
struct string
{
        int32 l;
        char *str;
};

internal void str_init(char *str, int32 l, Mem_Arena *a, String *s);
internal void str_die(String *string);
internal char *str_getchars(String *string);
internal int32 str_getlen(String *string);
internal int32 str_cmp(String *s1, String *s2);
internal void str_slice(String *s_orig, int32 i1, int32 i2, Mem_Arena *a,
			String *s_dest);
internal void str_append(String *s1, String *s2, Mem_Arena *a, String *s_dest);

/* function implementations */
internal void
str_init(char *str, int32 l, Mem_Arena *a, String *s)
{
        s->l = l;
        s->str = (char *)m_arena_alloc(a, l*sizeof(char));
        strcpy(s->str, str);
}

internal void
str_die(String *string)
{
        free(string->str);
}

internal char *
str_getchars(String *string)
{
        return string->str;
}

internal int32
str_getlen(String *string)
{
        return string->l;
}

internal int32
str_cmp(String *s1, String *s2)
{
        return memcmp(s1->str, s2->str, s1->l);
}

internal void
str_slice(String *s_orig, int32 i1, int32 i2, Mem_Arena *a, String *s_dest)
{
        Assert(i1 >= 0 && i1 < (s_orig->l - 1));
        Assert(i2 > 0 && i2 <= (s_orig->l - 1));
        Assert(i1 < i2);
        s_dest->l = i2 - i1 + 1;
        s_dest->str = m_arena_alloc(a, s_dest->l);
        if (s_dest->str != 0x0)
        {
                memcpy(s_dest->str, &s_orig->str[i1], s_dest->l);
                s_dest->str[s_dest->l-1] = 0;
        }
}

internal void
str_append(String *s1, String *s2, Mem_Arena *a, String *s_dest)
{
        s_dest->l = s1->l + s2->l - 1;
        s_dest->str = m_arena_alloc(a, s_dest->l);
        memcpy(s_dest->str, s1->str, s1->l - 1);
        memcpy(&s_dest->str[s1->l - 1], s2->str, s2->l);
}

#define BASE_STRING_H
#endif

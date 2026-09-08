#include "String.h"

/*
 * String.c — Implementacion de la biblioteca String
 *
 * REGLAS:
 *   - No usar <string.h> ni ninguna funcion estandar de cadenas
 *   - Al menos una funcion debe usar recursividad
 *   - Usar const en parametros que no se modifican
 */

/* ── IsEmpty — ya implementada, leerla antes de arrancar ────────────────── */

int IsEmpty(const char *s) {
    return *s == '\0';
}

/* ── GetLength — implementar siguiendo el README.md ─────────────────────── */

/* Version recursiva: sigue la especificacion
 * GetLength(e) = 0 ; GetLength(s) = 1 + GetLength(s[1..]) */
int GetLength(const char *s) {
    if (IsEmpty(s))
        return 0;
    return 1 + GetLength(s + 1);
}

/* ── AreEqual — tiene un bug, encontrarlo y corregirlo ──────────────────── */

int AreEqual(const char *s1, const char *s2) {
    while (!IsEmpty(s1) && !IsEmpty(s2)) {
        if (*s1 != *s2)
            return 0;
        s1++;
        s2++;
    }
    /* El while corta cuando alguna llega a '\0'. Son iguales solo si las dos
     * se terminaron a la vez: si una sigue teniendo caracteres, es mas larga. */
    return IsEmpty(s1) && IsEmpty(s2);
}

/* ── AreDecimalDigits — tiene un bug, encontrarlo y corregirlo ───────────── */

int AreDecimalDigits(const char *s) {
    if (IsEmpty(s)) return 0;  /* la cadena vacia no tiene ningun digito */
    for (const char *p = s; !IsEmpty(p); p++)
        if (*p < '0' || *p > '9')
            return 0;
    return 1;
}

/* ── Contains — implementar completo ────────────────────────────────────── */

/* Recorre la cadena de a un caracter hasta encontrar c o llegar al '\0'. */
int Contains(const char *s, char c) {
    for (const char *p = s; !IsEmpty(p); p++)
        if (*p == c)
            return 1;
    return 0;
}

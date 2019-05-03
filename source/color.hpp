// Bei Klassen ist die default - Sichtbarkeit immer private und bei structs immer public 
// Generell werden Structs eher für Klassen ohne Memberfunktionen, als reine Datensammlungen verwendet
// Datentransferobjekte (DTO) sind Klassen, die nur Daten speichern und weitergeben können
#ifndef COLOR_HPP
#define COLOR_HPP

struct Color
{
    float r = 0.5;
    float g = 0.5;
    float b = 0.5;
};

#endif 
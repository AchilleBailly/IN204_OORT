#ifndef ERROR_HPP
#define ERROR_HPP

#include "QString"
#include "dialog.h"

class Error
{
    const QString text;
public:
    Error(const QString& Text) : text(Text) {
        Dialog errorWindow(text);
        errorWindow.exec();
    }
};

#endif // ERROR_HPP

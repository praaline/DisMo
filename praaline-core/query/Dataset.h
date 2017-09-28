#ifndef DATASET_H
#define DATASET_H

/*
    Praaline - Core module - Queries and Datasets
    Copyright (c) 2011-2017 George Christodoulides

    This program or module is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version. It is provided
    for educational purposes and is distributed in the hope that it will
    be useful, but WITHOUT ANY WARRANTY; without even the implied
    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
    the GNU General Public License for more details.
*/

#include "pncore_global.h"
#include <QString>
#include <QPair>

namespace Praaline {
namespace Core {

class PRAALINE_CORE_SHARED_EXPORT Dataset
{
public:
    Dataset();

    void prepare();
};

} // namespace Core
} // namespace Praaline

#endif // DATASET_H

//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "inet/common/packet/chunk/FieldsChunk.h"

namespace inet {

FieldsChunk::FieldsChunk() :
    Chunk(),
    chunkLength(bit(-1)),
    serializedBytes(nullptr)
{
}

FieldsChunk::FieldsChunk(const FieldsChunk& other) :
    Chunk(other),
    chunkLength(other.chunkLength),
    serializedBytes(other.serializedBytes != nullptr ? new std::vector<uint8_t>(*other.serializedBytes) : nullptr)
{
}

FieldsChunk::~FieldsChunk()
{
    delete serializedBytes;
}

void FieldsChunk::handleChange()
{
    Chunk::handleChange();
    delete serializedBytes;
    serializedBytes = nullptr;
}

} // namespace

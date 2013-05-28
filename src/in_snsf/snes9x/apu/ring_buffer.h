/* Simple byte-based ring buffer. Licensed under public domain (C) BearOso. */

#ifndef __RING_BUFFER_H
#define __RING_BUFFER_H

#include <algorithm>
#include <cstring>

class ring_buffer
{
protected:
	int size;
	int buffer_size;
	int start;
	unsigned char *buffer;

public:
	ring_buffer(int buffer_size)
	{
		this->buffer_size = buffer_size;
		this->buffer = new unsigned char[this->buffer_size];
		this->clear();
	}

	~ring_buffer()
	{
		delete[] buffer;
	}

	bool push(unsigned char *src, int bytes)
	{
		if (this->space_empty() < bytes)
			return false;

		int end = (this->start + this->size) % this->buffer_size;
		int first_write_size = std::min(bytes, this->buffer_size - end);

		std::copy_n(&src[0], first_write_size, &this->buffer[end]);

		if (bytes > first_write_size)
			std::copy(&src[first_write_size], &src[bytes], &this->buffer[0]);

		this->size += bytes;

		return true;
	}

	int space_empty()
	{
		return this->buffer_size - this->size;
	}

	int space_filled()
	{
		return this->size;
	}

	void clear()
	{
		this->start = this->size = 0;
		std::fill_n(&this->buffer[0], this->buffer_size, 0);
	}

	void resize(int size)
	{
		delete[] this->buffer;
		this->buffer_size = size;
		this->buffer = new unsigned char[this->buffer_size];
		this->clear();
	}
};

#endif

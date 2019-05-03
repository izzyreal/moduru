#pragma once
#include <atomic>
#include <io/OutputStream.hpp>

#include <file/File.hpp>

#include <fstream>

#include <string>
#include <vector>

namespace moduru {
	namespace io {

		class FileOutputStream final
			: public OutputStream
		{

		public:
			typedef OutputStream super;

		private:
			bool append{ false };
			moduru::file::File* file{ nullptr };
			std::ofstream outputStream;

		private:
			void open(std::string name);

		public:
			void close() override;

		public:
			void finalize();

		public:
            void write(char b) override { OutputStream::write(b); };
			void write(std::vector<char> b) override;
			void write(std::vector<char> b, int off, int len) override;
			void writeBytes(std::vector<char> b, int off, int len);

        public:
			FileOutputStream(std::string name);
			FileOutputStream(moduru::file::File* file);
			FileOutputStream(std::string name, bool append);
			FileOutputStream(moduru::file::File* file, bool append);
			~FileOutputStream();

		};

	}
}

#include "FileCommandWriter.h"
#include "Util.h"

#include <chrono>
#include <filesystem>
#include <fstream>


FileCommandWriter::FileCommandWriter() : AsyncCommandWriter(2) {
}

void FileCommandWriter::write(const CommandBlock& commands, NumberOfThreads threadNumber) {
    auto filename = createFilename(threadNumber);
    std::ofstream file(filename);
    util::writeCommandsToStream(commands, file);
    file.flush();
    file.close();
}

std::string FileCommandWriter::createFilename(NumberOfThreads threadNumber) const {
    auto timeSinceEpoch = std::chrono::system_clock::now().time_since_epoch();
    auto timestamp = std::chrono::duration_cast<std::chrono::seconds>(timeSinceEpoch).count();

    std::string filename = "bulk";
    filename += std::to_string(timestamp);
    filename += "-th-";
    filename += std::to_string(threadNumber);
    std::string filenameAndExtension = filename + ".log";

    std::size_t index = 1;
    while (std::filesystem::exists(filenameAndExtension)) {
        //if a file already exists, add a numeric suffix (e.g. '-1') to the name
        filenameAndExtension = filename + '-' + std::to_string(index) + ".log";

        ++index;
    }
    return filenameAndExtension;
}

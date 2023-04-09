#include <iostream>

#include "Log.hpp"

std::ofstream* flt::Log::fout = NULL;

void
flt::Log::openFile(const std::string& path) {
	std::ofstream *new_fout = new std::ofstream();
	new_fout->open(path.c_str(), std::ios::out | std::ios::app);
	if (!new_fout->is_open()) {
		LOG_ERROR("Failed to open file \"" << path << "\" for logging.")
		return;
	}

	if (flt::Log::fout ) {
		LOG_INFO("Changing log files to \"" << path << "\".")
		flt::Log::fout->close();
		delete flt::Log::fout;
		flt::Log::fout = NULL;
	}

	flt::Log::fout = new_fout;
	LOG_INFO("Opened file \"" << path << "\" for logging.")
}

void
flt::Log::closeFile(void) {
	if (flt::Log::fout) {
		// if (flt::Log::fout->is_open()) {
			flt::Log::fout->close();
		// }
		delete flt::Log::fout;
		flt::Log::fout = NULL;
	}
}

void
flt::Log::trace(const std::stringstream& msg) {
	std::clog << FLT_LOG_TRACE_COLOR_FG << "[TRACE]" << FLT_LOG_RESET_COLOR << ": " <<
		msg.str() << FLT_LOG_RESET_COLOR << std::endl;
	if (flt::Log::fout ) {
		*flt::Log::fout << "[TRACE]: " << msg.str() << std::endl;
		flt::Log::fout->flush();
	}

}

void
flt::Log::debug(const std::stringstream& msg) {
	std::clog << FLT_LOG_DEBUG_COLOR_FG << "[DEBUG]" << FLT_LOG_RESET_COLOR << ": " <<
		msg.str()  << FLT_LOG_RESET_COLOR << std::endl;
	if (flt::Log::fout ) {
		*flt::Log::fout << "[DEBUG]: " << msg.str() << std::endl;
		flt::Log::fout->flush();
	}
}

void
flt::Log::info(const std::stringstream& msg) {
	std::clog << FLT_LOG_INFO_COLOR_FG << "[INFO]" << FLT_LOG_RESET_COLOR << ": " <<
		msg.str()  << FLT_LOG_RESET_COLOR << std::endl;
	if (flt::Log::fout ) {
		*flt::Log::fout << "[INFO]: " << msg.str() << std::endl;
		flt::Log::fout->flush();
	}
}

void
flt::Log::warn(const std::stringstream& msg) {
	std::clog << FLT_LOG_WARN_COLOR_FG << "[WARN]" << FLT_LOG_RESET_COLOR << ": " <<
		msg.str()  << FLT_LOG_RESET_COLOR << std::endl;
	if (flt::Log::fout ) {
		*flt::Log::fout << "[WARN]: " << msg.str() << std::endl;
		flt::Log::fout->flush();
	}
}

void
flt::Log::error(const std::stringstream& msg) {
	std::clog << FLT_LOG_ERROR_COLOR_FG << "[ERROR]" << FLT_LOG_RESET_COLOR << ": " <<
		msg.str()  << FLT_LOG_RESET_COLOR << std::endl;
	if (flt::Log::fout ) {
		*flt::Log::fout << "[ERROR]: " << msg.str() << std::endl;
		flt::Log::fout->flush();
	}
}

void
flt::Log::fatal(const std::stringstream& msg) {
	std::clog << FLT_LOG_FATAL_COLOR_FG << "[FATAL]" << FLT_LOG_RESET_COLOR << ": " <<
		msg.str()  << FLT_LOG_RESET_COLOR << std::endl;
	if (flt::Log::fout ) {
		*flt::Log::fout << "[FATAL]: " << msg.str() << std::endl;
		flt::Log::fout->flush();
	}
}

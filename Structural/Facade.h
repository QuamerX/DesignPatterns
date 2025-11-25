#pragma once

#include <string>
#include <iostream>

class HttpClient
{
public:
    std::string Get(const std::string& url)
    {
        return "SERVER DATA from " + url;
    }
};

class FileWriter
{
public:
    void Write(const std::string& path, const std::string& data)
    {
        std::cout << "Writing to " << path << ": " << data << "\n";
    }
};

class Logger
{
public:
    void Info(const std::string& msg)
    {
        std::cout << "[INFO] " << msg << "\n";
    }
};

class FileDownloaderFacade
{
public:
    void Download(const std::string& url, const std::string& savePath)
    {
        logger.Info("Starting download");

        auto data = http.Get(url);
        logger.Info("Downloaded " + std::to_string(data.size()) + " bytes");

        fileWriter.Write(savePath, data);
        logger.Info("File saved");
    }
        
private:
    HttpClient http;
    FileWriter fileWriter;
    Logger logger;
};
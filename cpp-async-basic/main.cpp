/*#include <iostream>
#include <vector>
#include <future>
#include <mutex>

std::shared_ptr<int> global_instance = std::make_shared<int>(0);
std::mutex m;
constexpr int max_loop = 10000000;


bool thread_func_shared_data()
{
    std::lock_guard<std::mutex> lock(m);

    for (int i = 0; i < max_loop; i++)
    {
        *global_instance = *global_instance + 1;
    }

    std::thread::id threadId = std::this_thread::get_id();
    std::cout << "Use count: " << global_instance.use_count() << std::endl;    
    std::cout << "Thread id: " <<std::this_thread::get_id() << std::endl;    
    std::cout << "--------------------" << std::endl;    
    
    
    return true;
}

bool thread_func()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::thread::id threadId = std::this_thread::get_id();
    std::cout << "Thread id: " <<std::this_thread::get_id() << std::endl;    
    std::cout << "--------------------" << std::endl;    
    
    return true;
}

int main() {
    // Imagine getting the tower-building team ready.
    *global_instance = 0;

    // Imagine calling your friends to start building the tower.
    std::vector<std::future<bool>> futureList;

    for (int i = 0; i < 10; ++i) {
        // Imagine each friend starting their job and giving you a note.
        futureList.push_back(std::async(thread_func));
    }

    // Imagine you're watching your friends build the tower.
    while (!futureList.empty()) {
        for (auto f = futureList.begin(); f != futureList.end();) {
            std::future_status fStat = f->wait_for(std::chrono::milliseconds(1));

            if (fStat == std::future_status::timeout) {
                std::cout << ".";
                ++f;
            } else {
                try {
                    // Imagine your friend gives you the finished tower part.
                    int result = f->get();
                    std::cout << "Result: " << result << '\n';
                } catch (const std::exception& e) {
                    std::cout << "Exception: " << e.what() << '\n';
                }
                f = futureList.erase(f);
            }
        }
    }

    std::cout << "Completed: " << global_instance << std::endl;

    return 0;
}
*/



#include <iostream>
#include <vector>
#include <future>
#include <fstream>
#include <mutex>

constexpr int totalFileSize = 1000000;
constexpr int chunkSize = 100000;
std::vector<char> fileData(totalFileSize);
std::mutex fileMutex;

int downloadChunk(int startIndex) {
    // Simulate downloading a chunk of data from the internet
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    std::lock_guard<std::mutex> lock(fileMutex);
    for (int i = 0; i < chunkSize; ++i) {
        fileData[startIndex + i] = 'X'; // Mark downloaded part
    }

    std::cout << "\nDownloaded block: " << startIndex <<"-"<< startIndex+chunkSize << std::endl;

    return (startIndex+chunkSize);
}

int downloadAndWait() {
    // Imagine a big file waiting to be downloaded.
    std::cout << "Downloading file (downloadAndWait)...\n";

    std::vector<std::future<int>> downloadTasks;

    // Divide the file into chunks and start downloading concurrently
    for (int i = 0; i < totalFileSize; i += chunkSize) {
        downloadTasks.push_back(std::async(std::launch::async, downloadChunk, i));
    }

    // Wait for all download tasks to complete
    for (auto& task : downloadTasks) {
        task.wait();
    }

    // Imagine the downloaded file is ready to be used.
    std::cout << "File downloaded.\n";

    // Check if the entire file is downloaded
    bool isFileComplete = true;
    for (char c : fileData) {
        if (c != 'X') {
            isFileComplete = false;
            break;
        }
    }

    if (isFileComplete) {
        std::cout << "Downloaded file is complete.\n";
    } else {
        std::cout << "Downloaded file is incomplete.\n";
    }

    return 0;
}


int downloadNonBlocking()
{
    // Imagine a big file waiting to be downloaded.
    std::cout << "Downloading file (downloadNonBlocking)...\n";

    using DownloadTaskList = std::vector<std::future<int>>;
    DownloadTaskList downloadTasks;

    // Divide the file into chunks and start downloading concurrently
    for (int i = 0; i < totalFileSize; i += chunkSize) {
        downloadTasks.push_back(std::async(std::launch::async, downloadChunk, i));
    }

    while (!downloadTasks.empty())
    {
         std::cout << "loop begin[";
        DownloadTaskList::iterator task = downloadTasks.begin();
        while (task != downloadTasks.end())
        {
            std::future_status fStat = task->wait_for(std::chrono::milliseconds(1));
            if (fStat == std::future_status::timeout)
            {
                std::cout << ".";
                ++task;
            }
            else {
                try {
                    //std::cout << "Downloaded file block end pos: "<< task->get() << '\n';
                }
                catch (const std::exception& e) {
                    std::cout << "Exception " << e.what() << '\n';
                }
                task = downloadTasks.erase(task);
            }
        }
        std::cout << "] loop end" << std::endl;
    }

    // Imagine the downloaded file is ready to be used.
    std::cout << "File downloaded.\n";

    // Check if the entire file is downloaded
    bool isFileComplete = true;
    for (char c : fileData) {
        if (c != 'X') {
            isFileComplete = false;
            break;
        }
    }

    if (isFileComplete) {
        std::cout << "Downloaded file is complete.\n";
    } else {
        std::cout << "Downloaded file is incomplete.\n";
    }


    return 0;
}

int main() 
{
    downloadAndWait();
    downloadNonBlocking();
}
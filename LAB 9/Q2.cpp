#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Logger {
    private:
        vector<string> LogMessages;
        const int MaxLogCount = 100;

        void StoreLog(const string& Severity, const string& ModuleName, const string& Message) {
            string FormattedMessage = "[" + Severity + "] [" + ModuleName + "] " + Message;
            if (LogMessages.size() >= MaxLogCount) {
                LogMessages.erase(LogMessages.begin()); // Remove the oldest log to maintain limit
            }
            LogMessages.push_back(FormattedMessage);    // Store the logs
        }
    public:
        void LogInfo(const string& ModuleName, const string& Message) {
            StoreLog("INFO", ModuleName, Message);
        }
        void LogWarning(const string& ModuleName, const string& Message) {
            StoreLog("WARN", ModuleName, Message);
        }
        void LogError(const string& ModuleName, const string& Message) {
            StoreLog("ERROR", ModuleName, Message);
        }
        // Friend class to allow Auditor restricted access
        friend class Auditor;
};

class Auditor {
    private:
        string AuditorName;
        string AccessKey;

        bool IsAuthenticated() const {
            return AccessKey == "SecureAccess123"; // A very basic authentication simulation used here
        }
    public:
        Auditor(const string& Name, const string& Key) : AuditorName(Name), AccessKey(Key) {
            // Paramatrized Constructor
        }
        vector<string> GetLogs(const Logger& LogSource) {
            if (IsAuthenticated()) {
                return LogSource.LogMessages; // Return a copy for read-only access
            } else {
                cout << "Access Denied: Invalid Auditor Credentials." << endl;
                return {};
            }
        }
};

// --- Example system modules calling the logger ---
void SimulateNetworkModule(Logger& AppLogger) {
    AppLogger.LogInfo("NetworkModule", "Connection established.");
    AppLogger.LogWarning("NetworkModule", "Packet delay detected.");
    AppLogger.LogError("NetworkModule", "Failed to resolve host.");
}

void SimulateDatabaseModule(Logger& AppLogger) {
    AppLogger.LogInfo("DatabaseModule", "Query executed successfully.");
    AppLogger.LogWarning("DatabaseModule", "Slow query warning.");
    AppLogger.LogError("DatabaseModule", "Database connection timeout.");
}

void SimulateUserModule(Logger& AppLogger) {
    AppLogger.LogInfo("UserModule", "User login successful.");
    AppLogger.LogWarning("UserModule", "Multiple failed login attempts.");
    AppLogger.LogError("UserModule", "Unauthorized access attempt.");
}

int main() {
    Logger AppLogger;

    // Simulating logs from different system modules [Logs are created here]
    SimulateNetworkModule(AppLogger);
    SimulateDatabaseModule(AppLogger);
    SimulateUserModule(AppLogger);

    // Attempt to retrieve logs as an auditor
    Auditor AuthenticatedAuditor("SecurityAuditor", "SecureAccess123"); // Grants Access
    Auditor UnauthorizedAuditor("HackerDude", "WrongPassword");         // DOesnt Grant Access

    cout << "\n--- Logs for Authenticated Auditor ---" << endl;
    vector<string> Logs = AuthenticatedAuditor.GetLogs(AppLogger);
    for (const string& Entry : Logs) {
        cout << Entry << endl;
    }

    cout << "\n--- Logs for Unauthorized Auditor ---" << endl;
    UnauthorizedAuditor.GetLogs(AppLogger);

    return 0;
}

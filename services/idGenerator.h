// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

class IdGenerator {
private:
    int workerId;
    int transactionId;
    int categoryId;

    IdGenerator();
    
    IdGenerator(const IdGenerator&) = delete;
    IdGenerator& operator=(const IdGenerator&) = delete;

public:
    static IdGenerator& getInstance();

    int getWorkerId() const;
    int getTransactionId() const;
    int getCategoryId() const;

    void setWorkerId(int workerId);
    void setTransactionId(int transactionId);
    void setCategoryId(int categoryId);
};
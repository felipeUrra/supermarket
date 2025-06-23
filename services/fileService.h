// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "../transaction.h"
#include "../supermarket.h"

class FileService {
public:
    FileService() = delete;
    virtual ~FileService() = default;

    static void createReceipt(Transaction* transaction);
};
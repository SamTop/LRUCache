#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <iostream>
#include <unordered_map>
#include <list>
#include <mutex>
#include <optional>

template <typename Key, typename Value>
class LRUCache {
public:
    explicit LRUCache(size_t capacity) : capacity_(capacity) {}

    std::optional<Value> get(const Key& key) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = cacheMap_.find(key);
        if (it == cacheMap_.end()) {
            return std::nullopt;
        }
        cacheList_.splice(cacheList_.begin(), cacheList_, it->second);
        return it->second->second;
    }

    void put(const Key& key, Value& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = cacheMap_.find(key);
        if (it != cacheMap_.end()) {
            cacheList_.erase(it->second);
            cacheMap_.erase(it);
        } else if (cacheList_.size() >= capacity_) {
            auto lru = cacheList_.back();
            cacheMap_.erase(lru.first);
            cacheList_.pop_back();
        }
        cacheList_.emplace_front(key, value);
        cacheMap_[key] = cacheList_.begin();
    }
private:
    size_t capacity_;
    std::list<std::pair<Key, Value>> cacheList_;
    std::unordered_map<Key, typename std::list<std::pair<Key, Value>>::iterator> cacheMap_;
    std::mutex mutex_;
};

#endif

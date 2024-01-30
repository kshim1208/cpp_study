#pragma once

# include <cstddef>

template
class MemoryPool
{
    public:
        // MemoryPool의 한 블록의 크기를 설정
        MemoryPool(size_t size);
        ~MemoryPool();
        MemoryPool(MemoryPool& cp);
        MemoryPool& operator=(MemoryPool& cp);

        // type*    getMemory();
        // void     returnMemory(type*);
            // 해제할 떄 사이즈는 어떻게 알 수 있을까?
            // 

    private:
        // MemoryBlock
            // 어떤 단위로 표현하는게 좋을까? 그냥 포인터?
        
        // 현재 MemoryBlock 위치
        size_t  block_size = 0;
}
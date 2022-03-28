#pragma once


#include <thread>
#include <iostream>
#include "network.hpp"
#include "syscNetProto.hpp"


class ModelSimServer
{
    public:
    
        // --------------------------------------------------------------------------------------------------------------------------------------------------
        /**
         *      \brief          constructor for ModelSimServer class
         *      \return         returns pointer to ModelSimServer class
         */
        // --------------------------------------------------------------------------------------------------------------------------------------------------
        ModelSimServer();


        // --------------------------------------------------------------------------------------------------------------------------------------------------
        /**
         *      \brief          destructor for ModelSimServer class
         */
        // --------------------------------------------------------------------------------------------------------------------------------------------------
        ~ModelSimServer();


        // --------------------------------------------------------------------------------------------------------------------------------------------------
        /**
        *       \brief          function for listening on network socket
        *
        *       \return         -1 if listening fails
        */
        // --------------------------------------------------------------------------------------------------------------------------------------------------
        int listenOnSocket();


        // --------------------------------------------------------------------------------------------------------------------------------------------------
        /**
        *       \brief          thread responsible for hardware communication
        *
        */
        // --------------------------------------------------------------------------------------------------------------------------------------------------
        static void hardware_thread();
        
        
        // --------------------------------------------------------------------------------------------------------------------------------------------------
        /**
        *       \brief        thread responsible for hardware communication
        *
        */
        // --------------------------------------------------------------------------------------------------------------------------------------------------     
        static void software_thread();
        

        int m_socket; /*!< socket for listen on the network */
        static int m_hard_soc; /*!< hardware socket */
        static int m_soft_soc; /*!< software socket */
        std::thread* m_hard_thrd_hndl; /*!< handle for hardware thread  */
        std::thread* m_soft_thrd_hndl; /*!< handle for software thread */
};

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
		 *		@brief			function description
		 *		@param	param0	param0 description
		 *		@param	param1	param1 description
		 *		@return			0 success, 1 failure
		 */
		// --------------------------------------------------------------------------------------------------------------------------------------------------
        ModelSimServer();


		// --------------------------------------------------------------------------------------------------------------------------------------------------
		/**
		 *		@brief			function description
		 *		@param	param0	param0 description
		 *		@param	param1	param1 description
		 *		@return			0 success, 1 failure
		 */
		// --------------------------------------------------------------------------------------------------------------------------------------------------
		~ModelSimServer();

        
        /**
        * function
        *
        * \param[in] 
        * \param[in, out] 
        * \param[in] 
        *
        * \return 
        */
        int listenOnSocket();


        /**
        * function
        *
        * \param[in] 
        * \param[in, out] 
        * \param[in] 
        *
        * \return 
        */ 
        static void hardware_thread();
        
        
        /**
        * function
        *
        * \param[in] 
        * \param[in, out] 
        * \param[in] 
        *
        * \return 
        */        
        static void software_thread();
        

        int m_socket;
        static int m_hard_soc;
        static int m_soft_soc;
        std::thread* m_hard_thrd_hndl;
        std::thread* m_soft_thrd_hndl;
};

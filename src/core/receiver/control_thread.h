/*!
 * \file control_thread.h
 * \brief Interface of the receiver control plane
 * \author Carlos Aviles, 2010. carlos.avilesr(at)googlemail.com
 *
 * GNSS Receiver Control Plane: connects the flowgraph, starts running it,
 * and while it does not stop, reads the control messages generated by the blocks,
 * process them, and apply the corresponding actions.
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2012  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * GNSS-SDR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * at your option) any later version.
 *
 * GNSS-SDR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNSS-SDR. If not, see <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */

#ifndef GNSS_SDR_CONTROL_THREAD_H_
#define GNSS_SDR_CONTROL_THREAD_H_

#include <boost/thread/thread.hpp>
#include <gnuradio/gr_msg_queue.h>
#include "control_message_factory.h"
#include "gnss_sdr_supl_client.h"

class GNSSFlowgraph;
class ConfigurationInterface;


/*!
 * \brief This class represents the main thread of the application, aka Control Thread.
 */
class ControlThread
{
public:
    /*!
     * \brief Default constructor
     */
    ControlThread();

    /*!
     * \brief Constructor that initializes the class with parameters
     *
     * \param[in] configuration Pointer to a ConfigurationInterface
     */
    ControlThread(ConfigurationInterface *configuration);

    //! \brief Virtual destructor. Derived classes must implement the destructor
    virtual ~ControlThread();

    /*! \brief Runs the control thread
     *
     *  This is the main loop that reads and process the control messages:
     *  - Connect the GNSS receiver flowgraph;
     *  - Start the GNSS receiver flowgraph;
     *  while (flowgraph_->running() && !stop)_{
     *  - Read control messages and process them; }
     */
    void run();

    /*!
     * \brief Sets the control_queue
     *
     * \param[in] gr_msg_queue_sptr control_queue
     */
    void set_control_queue(gr_msg_queue_sptr control_queue);


    unsigned int processed_control_messages()
    {
        return processed_control_messages_;
    }

    unsigned int applied_actions()
    {
        return applied_actions_;
    }

    /*!
     * \brief Instantiates a flowgraph
     *
     * \return Returns a flowgraph object
     */
    GNSSFlowgraph* flowgraph()
    {
        return flowgraph_;
    }


private:

    /*!
     * \brief SUPL assistance classes
     */
	gnss_sdr_supl_client supl_client_acquisition_;
	gnss_sdr_supl_client supl_client_ephemeris_;
	int supl_mcc; // Current network MCC (Mobile country code), 3 digits.
	int supl_mns; //Current network MNC (Mobile Network code), 2 or 3 digits.
	int supl_lac; // Current network LAC (Location area code),16 bits, 1-65520 are valid values.
	int supl_ci; // Cell Identity (16 bits, 0-65535 are valid values).

    void init();
    bool read_assistance_from_XML();
    void read_control_messages();
    void process_control_messages();
    void gps_ephemeris_data_collector();
    void gps_utc_model_data_collector();
    void gps_iono_data_collector();
    void apply_action(unsigned int what);
    GNSSFlowgraph *flowgraph_;
    ConfigurationInterface *configuration_;
    gr_msg_queue_sptr control_queue_;
    ControlMessageFactory *control_message_factory_;
    std::vector<ControlMessage*> *control_messages_;
    bool stop_;
    bool delete_configuration_;
    unsigned int processed_control_messages_;
    unsigned int applied_actions_;
    boost::thread keyboard_thread_;
    boost::thread gps_ephemeris_data_collector_thread_;
    boost::thread gps_iono_data_collector_thread_;
    boost::thread gps_utc_model_data_collector_thread_;
    void keyboard_listener();
};

#endif /*GNSS_SDR_CONTROL_THREAD_H_*/

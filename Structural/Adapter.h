#include <iostream>
#include <vector>
#include <string>

/**
 * @namespace Structural
 * @brief Contains the implementation of the Adapter design pattern for various communication interfaces.
 * * This namespace defines the Target interface (IMessageSender), the Adaptees (UDPComm, SerialComm, SharedMemoryComm),
 * the corresponding Adapters (UDPAdapter, SerialAdapter, SharedMemoryAdapter), and the Client class.
 */
namespace Structural
{
	/**
	 * @brief The Target Interface that the client expects to use.
	 * * Defines the common contract for sending messages, allowing the client to be decoupled
	 * from the specific communication technology.
	 */
	class IMessageSender
	{
	public:
		/**
		 * @brief Virtual destructor to allow for proper cleanup of derived classes.
		 */
		virtual ~IMessageSender() = default;

		/**
		 * @brief Sends a message using the underlying communication mechanism.
		 * @param message The message data to be sent (as a standard string).
		 * @return true if the message was successfully sent, false otherwise.
		 */
		virtual bool Send(const std::string& message) const = 0;
	};

	/**
	 * @brief The first Adaptee: Incompatible UDP Communication class.
	 * * This class has an incompatible interface (SendDatagram) and uses a non-standard package type (vector<uint8_t>).
	 */
	class UDPComm
	{
	public:
		/**
		 * @brief Sends data using the UDP protocol.
		 * @param packet_data The data buffer, expected as a vector of bytes.
		 */
		void SendDatagram(const std::vector<uint8_t>& packet_data) const
		{
			std::cout << "UDP: Sending packet of size " << packet_data.size() << "\n";
		}
	};

	/**
	 * @brief The second Adaptee: Incompatible Serial Communication class.
	 * * This class has an incompatible interface (TransmitBytes) and uses C-style byte buffers.
	 */
	class SerialComm
	{
	public:
		/**
		 * @brief Transmits raw bytes over a serial connection.
		 * @param data_buffer A pointer to the raw byte data.
		 * @param length The number of bytes to transmit.
		 */
		void TransmitBytes(const uint8_t* data_buffer, size_t length) const
		{
			std::cout << "Serial: Transmitting " << length << " bytes\n";
		}
	};

	/**
	 * @brief The third Adaptee: Incompatible Shared Memory Communication class.
	 * * This class has an incompatible interface (PushData) but naturally accepts std::string.
	 */
	class SharedMemoryComm
	{
	public:
		/**
		 * @brief Pushes a data payload into shared memory.
		 * @param payload The string data to be written.
		 */
		void PushData(const std::string& payload) const
		{
			std::cout << "Shared Memory: Pushing payload: " << payload << "\n";
		}
	};

	/**
	 * @brief The Adapter for Shared Memory Communication.
	 * * Adapts the SharedMemoryComm interface to the IMessageSender interface.
	 * This is a clean example of the Adapter pattern using Composition (strict ownership).
	 */
	class SharedMemoryAdapter : public IMessageSender
	{
	private:
		/// @brief The instance of the Adaptee, demonstrating composition.
		SharedMemoryComm adaptee_;

	public:
		/**
		 * @brief Implementation of the target interface.
		 * * Translates the IMessageSender::Send() call directly into the SharedMemoryComm::PushData() call.
		 * @param message The message to send.
		 * @return Always true upon calling the adaptee method.
		 */
		bool Send(const std::string& message) const override
		{
			adaptee_.PushData(message);
			return true;
		}
	};

	/**
	 * @brief The Adapter for UDP Communication.
	 * * Adapts the UDPComm interface to the IMessageSender interface.
	 * Translates the std::string message into a std::vector<uint8_t> packet required by the adaptee.
	 */
	class UDPAdapter : public IMessageSender
	{
	private:
		/// @brief The instance of the Adaptee, demonstrating composition.
		UDPComm adaptee_;

	public:
		/**
		 * @brief Implementation of the target interface.
		 * * Translates the std::string message to a std::vector<uint8_t> and calls SendDatagram.
		 * @param message The message to send.
		 * @return Always true upon calling the adaptee method.
		 */
		bool Send(const std::string& message) const override
		{
			std::vector<uint8_t> packet(message.begin(), message.end());

			adaptee_.SendDatagram(packet);
			return true;
		}
	};

	/**
	 * @brief The Adapter for Serial Communication.
	 * * Adapts the SerialComm interface to the IMessageSender interface.
	 * Translates the std::string message into a raw pointer and length required by the adaptee.
	 */
	class SerialAdapter : public IMessageSender
	{
	private:
		/// @brief The instance of the Adaptee, demonstrating composition.
		SerialComm adaptee_;

	public:
		/**
		 * @brief Implementation of the target interface.
		 * * Translates the std::string message into a raw buffer pointer and calls TransmitBytes.
		 * @param message The message to send.
		 * @return Always true upon calling the adaptee method.
		 */
		bool Send(const std::string& message) const override
		{
			adaptee_.TransmitBytes(reinterpret_cast<const uint8_t*>(message.data()), message.size());
			return true;
		}
	};

	/**
	 * @brief The Client class that uses the IMessageSender interface.
	 * * The Client is decoupled from the specific communication method and relies only on the target interface.
	 */
	class Client
	{
	public:
		/**
		 * @brief Constructs the Client with an initial IMessageSender adapter.
		 * @param sender A pointer to the adapter implementing IMessageSender (Aggregation).
		 */
		Client(IMessageSender* sender) : _sender_(sender) {}

		/**
		 * @brief Changes the communication interface at runtime.
		 * @param newSender A pointer to the new adapter.
		 */
		void ChangeAdapter(IMessageSender* newSender)
		{
			_sender_ = newSender;
		}

		/**
		 * @brief Sends a message using the currently configured adapter.
		 * @param message The message content to be sent.
		 */
		void SendMessage(std::string message)
		{
			_sender_->Send(message);
		}

	private:
		/// @brief Pointer to the current active adapter (IMessageSender).
		IMessageSender* _sender_;
	};
}
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node
{
public:
    PublisherNode() : Node("cpp_publisher")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);

        timer_ = this->create_wall_timer(
            1s,
            std::bind(&PublisherNode::publish_message, this));
    }

private:
    void publish_message()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello from C++ Publisher";

        RCLCPP_INFO(this->get_logger(), "%s", message.data.c_str());

        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PublisherNode>());
    rclcpp::shutdown();
    return 0;
}

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class PublisherNode(Node):

    def __init__(self):
        super().__init__('py_publisher')

        self.publisher_ = self.create_publisher(String, 'topic', 10)

        self.timer = self.create_timer(1.0, self.publish_message)

    def publish_message(self):
        msg = String()
        msg.data = 'Hello from Python Publisher'

        self.publisher_.publish(msg)

        self.get_logger().info(msg.data)

def main(args=None):
    rclpy.init(args=args)

    node = PublisherNode()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

/**
 * @file /include/qtros/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date August 2017
 **/

#ifndef qtros_QNODE_HPP_
#define qtros_QNODE_HPP_

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif

#include <string>
#include <QThread>
#include <QStringListModel>

namespace qtros {

class QNode : public QThread {
    Q_OBJECT
public:
    QNode(int argc, char** argv, const std::string &name );
    virtual ~QNode();

    bool init();
    bool init(const std::string &master_url, const std::string &host_url);
    void shutdown();
    virtual void run()=0;

    enum LogLevel {
        Debug,
        Info,
        Warn,
        Error,
        Fatal
    };
    const std::string& nodeName(){return node_name;}


    void setRightAngle(float angle);
    void setLeftAngle(float angle);
    float getRightAngle(void);
    float getLeftAngle(void);

Q_SIGNALS:
    void rosShutdown();

protected:
    virtual void ros_comms_init()=0;
    int init_argc;
    char** init_argv;
    const std::string node_name;

    float right_angle;
    float left_angle;

private:

};

}  // namespace qtros

#endif /* qtros_QNODE_HPP_ */

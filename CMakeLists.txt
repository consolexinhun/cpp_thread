cmake_minimum_required(VERSION 3.16)
project(thread)

set(ROOT ${PROJECT_SOURCE_DIR})

add_compile_options(-O3 -fPIC)


# include_directories(${ROOT}/src/cpp/thirdparty)
# include_directories(/opt/ros/noetic/include/)

# include_directories(
#     /usr/include
# )

# find_package(pybind11 REQUIRED)

# link_directories(${ROOT})
# link_directories(/opt/ros/noetic/lib/)


# add_library(basics SHARED ${ROOT}/src/to_py/basics.cpp)
# target_link_libraries(basics awm pybind11::module )

add_executable(thread ${ROOT}/02/thread.cpp)
target_link_libraries(thread pthread)

add_executable(detach ${ROOT}/02/detach.cpp)
target_link_libraries(detach pthread)

add_executable(create ${ROOT}/02/create.cpp)
target_link_libraries(create pthread)


add_executable(get_id ${ROOT}/03/get_id.cpp)
target_link_libraries(get_id pthread)

add_executable(param_by_reference ${ROOT}/03/param_by_reference.cpp)
target_link_libraries(param_by_reference pthread)
# add_executable(test2 ${ROOT}/test2.cpp)

add_executable(param_by_reference_class ${ROOT}/03/param_by_reference_class.cpp)
target_link_libraries(param_by_reference_class pthread)

add_executable(param_by_pointer ${ROOT}/03/param_by_pointer.cpp)
target_link_libraries(param_by_pointer pthread)

add_executable(param_by_implicit ${ROOT}/03/param_by_implicit.cpp)
target_link_libraries(param_by_implicit pthread)

add_executable(multi_thread ${ROOT}/04/multi_thread.cpp)
target_link_libraries(multi_thread pthread)

add_executable(multi_thread_read ${ROOT}/04/multi_thread_read.cpp)
target_link_libraries(multi_thread_read pthread)

add_executable(multi_thread_write ${ROOT}/04/multi_thread_write.cpp)
target_link_libraries(multi_thread_write pthread)

add_executable(lock ${ROOT}/05/lock.cpp)
target_link_libraries(lock pthread)

add_executable(deadlock ${ROOT}/05/deadlock.cpp)
target_link_libraries(deadlock pthread)

add_executable(avoid_deadlock ${ROOT}/05/avoid_deadlock.cpp)
target_link_libraries(avoid_deadlock pthread)


add_executable(lock_many ${ROOT}/05/lock_many.cpp)
target_link_libraries(lock_many pthread)

add_executable(adopt_lock ${ROOT}/05/adopt_lock.cpp)
target_link_libraries(adopt_lock pthread)

add_executable(unique_lock ${ROOT}/06/unique_lock.cpp)
target_link_libraries(unique_lock pthread)

add_executable(owns_lock ${ROOT}/06/owns_lock.cpp)
target_link_libraries(owns_lock pthread)

add_executable(unlock ${ROOT}/06/unlock.cpp)
target_link_libraries(unlock pthread)

add_executable(trylock ${ROOT}/06/trylock.cpp)
target_link_libraries(trylock pthread)

add_executable(release ${ROOT}/06/release.cpp)
target_link_libraries(release pthread)

add_executable(unique_lock_mutex ${ROOT}/06/unique_lock_mutex.cpp)
target_link_libraries(unique_lock_mutex pthread)

add_executable(operate ${ROOT}/06/operate.cpp)
target_link_libraries(operate pthread)


add_executable(lazy_singleton ${ROOT}/07/lazy_singleton.cpp)
target_link_libraries(lazy_singleton pthread)

add_executable(eager_singleton ${ROOT}/07/eager_singleton.cpp)
target_link_libraries(eager_singleton pthread)

add_executable(lazy_singleton_callonce ${ROOT}/07/lazy_singleton_callonce.cpp)
target_link_libraries(lazy_singleton_callonce pthread)

add_executable(recycle ${ROOT}/07/recycle.cpp)
target_link_libraries(recycle pthread)

add_executable(condition_variable ${ROOT}/08/condition_variable.cpp)
target_link_libraries(condition_variable pthread)

add_executable(notify_one ${ROOT}/08/notify_one.cpp)
target_link_libraries(notify_one pthread)

add_executable(notify_all ${ROOT}/08/notify_all.cpp)
target_link_libraries(notify_all pthread)

add_executable(wait ${ROOT}/08/wait.cpp)
target_link_libraries(wait pthread)

add_executable(wait_for ${ROOT}/08/wait_for.cpp)
target_link_libraries(wait_for pthread)

add_executable(wait_util ${ROOT}/08/wait_util.cpp)
target_link_libraries(wait_util pthread)

add_executable(future_valid ${ROOT}/09/future_valid.cpp)
target_link_libraries(future_valid pthread)

add_executable(future_get ${ROOT}/09/future_get.cpp)
target_link_libraries(future_get pthread)

add_executable(future_wait ${ROOT}/09/future_wait.cpp)
target_link_libraries(future_wait pthread)

add_executable(future_wait_for ${ROOT}/09/future_wait_for.cpp)
target_link_libraries(future_wait_for pthread)

add_executable(async1 ${ROOT}/09/async1.cpp)
target_link_libraries(async1 pthread)

add_executable(async2 ${ROOT}/09/async2.cpp)
target_link_libraries(async2 pthread)

add_executable(async3 ${ROOT}/09/async3.cpp)
target_link_libraries(async3 pthread)

add_executable(packaged_task ${ROOT}/09/packaged_task.cpp)
target_link_libraries(packaged_task pthread)

add_executable(promise ${ROOT}/09/promise.cpp)
target_link_libraries(promise pthread)

add_executable(share_future ${ROOT}/10/share_future.cpp)
target_link_libraries(share_future pthread)

add_executable(atomic1 ${ROOT}/10/atomic1.cpp)
target_link_libraries(atomic1 pthread)

add_executable(atomic2 ${ROOT}/10/atomic2.cpp)
target_link_libraries(atomic2 pthread)

add_executable(atomic3 ${ROOT}/10/atomic3.cpp)
target_link_libraries(atomic3 pthread)

add_executable(atomic_flag ${ROOT}/10/atomic_flag.cpp)
target_link_libraries(atomic_flag pthread)

add_executable(launch_async ${ROOT}/11/launch_async.cpp)
target_link_libraries(launch_async pthread)


add_executable(launch_deferred ${ROOT}/11/launch_deferred.cpp)
target_link_libraries(launch_deferred pthread)


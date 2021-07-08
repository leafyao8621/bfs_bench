program bench
    use core
    implicit none
    type(Runner) :: r
    character(len=1000) :: argv
    integer :: stat
    integer :: verbose
    integer :: show_graph
    integer :: show_path
    if (iargc() .eq. 4) then
        call get_command_argument(1, argv)
        call runner_initialize(r, argv, 1)
        call get_command_argument(2, argv)
        read (argv, *, iostat = stat) verbose
        call get_command_argument(3, argv)
        read (argv, *, iostat = stat) show_graph
        call get_command_argument(4, argv)
        read (argv, *, iostat = stat) show_path
        call runner_run(r, verbose .ne. 0, show_graph .ne. 0, show_path .ne. 0)
        call runner_finalize(r)
    else
        print *, "fn, verbose, graph, path"
    end if
end program

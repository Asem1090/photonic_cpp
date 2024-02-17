#pragma once

template<typename FUNCTYPE, typename... ARGSTYPES>
auto benchmark(FUNCTYPE(*func)(ARGSTYPES...), ARGSTYPES... args);
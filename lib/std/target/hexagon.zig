// SPDX-License-Identifier: MIT
// Copyright (c) 2015-2020 Zig Contributors
// This file is part of [zig](https://ziglang.org/), which is MIT licensed.
// The MIT license requires this copyright notice to be included in all copies
// and substantial portions of the software.
const std = @import("../std.zig");
const CpuFeature = std.Target.Cpu.Feature;
const CpuModel = std.Target.Cpu.Model;

pub const Feature = enum {
    audio,
    compound,
    duplex,
    hvx,
    hvx_length128b,
    hvx_length64b,
    hvxv60,
    hvxv62,
    hvxv65,
    hvxv66,
    hvxv67,
    long_calls,
    mem_noshuf,
    memops,
    noreturn_stack_elim,
    nvj,
    nvs,
    packets,
    prev65,
    reserved_r19,
    small_data,
    tinycore,
    unsafe_fp,
    v5,
    v55,
    v60,
    v62,
    v65,
    v66,
    v67,
    zreg,
};

pub usingnamespace CpuFeature.feature_set_fns(Feature);

pub const all_features = blk: {
    const len = @typeInfo(Feature).Enum.fields.len;
    std.debug.assert(len <= CpuFeature.Set.needed_bit_count);
    var result: [len]CpuFeature = undefined;
    result[@enumToInt(Feature.audio)] = .{
                     .llvm_name = "audio",
                     .description = "Hexagon Audio extension instructions",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.compound)] = .{
                     .llvm_name = "compound",
                     .description = "Use compound instructions",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.duplex)] = .{
                     .llvm_name = "duplex",
                     .description = "Enable generation of duplex instruction",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.hvx)] = .{
                     .llvm_name = "hvx",
                     .description = "Hexagon HVX instructions",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.hvx_length128b)] = .{
                     .llvm_name = "hvx-length128b",
                     .description = "Hexagon HVX 128B instructions",
                     .dependencies = featureSet(&[_]Feature{
                                      .hvx,
                     }),
    };
    result[@enumToInt(Feature.hvx_length64b)] = .{
                     .llvm_name = "hvx-length64b",
                     .description = "Hexagon HVX 64B instructions",
                     .dependencies = featureSet(&[_]Feature{
                                      .hvx,
                     }),
    };
    result[@enumToInt(Feature.hvxv60)] = .{
                     .llvm_name = "hvxv60",
                     .description = "Hexagon HVX instructions",
                     .dependencies = featureSet(&[_]Feature{
                                      .hvx,
                     }),
    };
    result[@enumToInt(Feature.hvxv62)] = .{
                     .llvm_name = "hvxv62",
                     .description = "Hexagon HVX instructions",
                     .dependencies = featureSet(&[_]Feature{
                                      .hvx,
                                      .hvxv60,
                     }),
    };
    result[@enumToInt(Feature.hvxv65)] = .{
                     .llvm_name = "hvxv65",
                     .description = "Hexagon HVX instructions",
                     .dependencies = featureSet(&[_]Feature{
                                      .hvx,
                                      .hvxv60,
                                      .hvxv62,
                     }),
    };
    result[@enumToInt(Feature.hvxv66)] = .{
                     .llvm_name = "hvxv66",
                     .description = "Hexagon HVX instructions",
                     .dependencies = featureSet(&[_]Feature{
                                      .hvx,
                                      .hvxv60,
                                      .hvxv62,
                                      .hvxv65,
                                      .zreg,
                     }),
    };
    result[@enumToInt(Feature.hvxv67)] = .{
                     .llvm_name = "hvxv67",
                     .description = "Hexagon HVX instructions",
                     .dependencies = featureSet(&[_]Feature{
                                      .hvxv60,
                                      .hvxv62,
                                      .hvxv65,
                                      .hvxv66,
                     }),
    };
    result[@enumToInt(Feature.long_calls)] = .{
                     .llvm_name = "long-calls",
                     .description = "Use constant-extended calls",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.mem_noshuf)] = .{
                     .llvm_name = "mem_noshuf",
                     .description = "Supports mem_noshuf feature",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.memops)] = .{
                     .llvm_name = "memops",
                     .description = "Use memop instructions",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.noreturn_stack_elim)] = .{
                     .llvm_name = "noreturn-stack-elim",
                     .description = "Eliminate stack allocation in a noreturn function when possible",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.nvj)] = .{
                     .llvm_name = "nvj",
                     .description = "Support for new-value jumps",
                     .dependencies = featureSet(&[_]Feature{
                                      .packets,
                     }),
    };
    result[@enumToInt(Feature.nvs)] = .{
                     .llvm_name = "nvs",
                     .description = "Support for new-value stores",
                     .dependencies = featureSet(&[_]Feature{
                                      .packets,
                     }),
    };
    result[@enumToInt(Feature.packets)] = .{
                     .llvm_name = "packets",
                     .description = "Support for instruction packets",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.prev65)] = .{
                     .llvm_name = "prev65",
                     .description = "Support features deprecated in v65",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserved_r19)] = .{
                     .llvm_name = "reserved-r19",
                     .description = "Reserve register R19",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.small_data)] = .{
                     .llvm_name = "small-data",
                     .description = "Allow GP-relative addressing of global variables",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.tinycore)] = .{
                     .llvm_name = "tinycore",
                     .description = "Hexagon Tiny Core",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.unsafe_fp)] = .{
                     .llvm_name = "unsafe-fp",
                     .description = "Use unsafe FP math",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.v5)] = .{
                     .llvm_name = "v5",
                     .description = "Enable Hexagon V5 architecture",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.v55)] = .{
                     .llvm_name = "v55",
                     .description = "Enable Hexagon V55 architecture",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.v60)] = .{
                     .llvm_name = "v60",
                     .description = "Enable Hexagon V60 architecture",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.v62)] = .{
                     .llvm_name = "v62",
                     .description = "Enable Hexagon V62 architecture",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.v65)] = .{
                     .llvm_name = "v65",
                     .description = "Enable Hexagon V65 architecture",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.v66)] = .{
                     .llvm_name = "v66",
                     .description = "Enable Hexagon V66 architecture",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.v67)] = .{
                     .llvm_name = "v67",
                     .description = "Enable Hexagon V67 architecture",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.zreg)] = .{
                     .llvm_name = "zreg",
                     .description = "Hexagon ZReg extension instructions",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    const ti = @typeInfo(Feature);
    for (result) |*elem, i| {
                     elem.index = i;
                     elem.name = ti.Enum.fields[i].name;
    }
    break :blk result;
};

pub const cpu = struct {
    pub const generic = CpuModel{
                     .name = "generic",
                     .llvm_name = "generic",
                     .features = featureSet(&[_]Feature{
                                      .compound,
                                      .duplex,
                                      .memops,
                                      .nvj,
                                      .nvs,
                                      .packets,
                                      .prev65,
                                      .small_data,
                                      .v5,
                                      .v55,
                                      .v60,
                     }),
    };
    pub const hexagonv5 = CpuModel{
                     .name = "hexagonv5",
                     .llvm_name = "hexagonv5",
                     .features = featureSet(&[_]Feature{
                                      .compound,
                                      .duplex,
                                      .memops,
                                      .nvj,
                                      .nvs,
                                      .packets,
                                      .prev65,
                                      .small_data,
                                      .v5,
                     }),
    };
    pub const hexagonv55 = CpuModel{
                     .name = "hexagonv55",
                     .llvm_name = "hexagonv55",
                     .features = featureSet(&[_]Feature{
                                      .compound,
                                      .duplex,
                                      .memops,
                                      .nvj,
                                      .nvs,
                                      .packets,
                                      .prev65,
                                      .small_data,
                                      .v5,
                                      .v55,
                     }),
    };
    pub const hexagonv60 = CpuModel{
                     .name = "hexagonv60",
                     .llvm_name = "hexagonv60",
                     .features = featureSet(&[_]Feature{
                                      .compound,
                                      .duplex,
                                      .memops,
                                      .nvj,
                                      .nvs,
                                      .packets,
                                      .prev65,
                                      .small_data,
                                      .v5,
                                      .v55,
                                      .v60,
                     }),
    };
    pub const hexagonv62 = CpuModel{
                     .name = "hexagonv62",
                     .llvm_name = "hexagonv62",
                     .features = featureSet(&[_]Feature{
                                      .compound,
                                      .duplex,
                                      .memops,
                                      .nvj,
                                      .nvs,
                                      .packets,
                                      .prev65,
                                      .small_data,
                                      .v5,
                                      .v55,
                                      .v60,
                                      .v62,
                     }),
    };
    pub const hexagonv65 = CpuModel{
                     .name = "hexagonv65",
                     .llvm_name = "hexagonv65",
                     .features = featureSet(&[_]Feature{
                                      .compound,
                                      .duplex,
                                      .mem_noshuf,
                                      .memops,
                                      .nvj,
                                      .nvs,
                                      .packets,
                                      .small_data,
                                      .v5,
                                      .v55,
                                      .v60,
                                      .v62,
                                      .v65,
                     }),
    };
    pub const hexagonv66 = CpuModel{
                     .name = "hexagonv66",
                     .llvm_name = "hexagonv66",
                     .features = featureSet(&[_]Feature{
                                      .compound,
                                      .duplex,
                                      .mem_noshuf,
                                      .memops,
                                      .nvj,
                                      .nvs,
                                      .packets,
                                      .small_data,
                                      .v5,
                                      .v55,
                                      .v60,
                                      .v62,
                                      .v65,
                                      .v66,
                     }),
    };
    pub const hexagonv67 = CpuModel{
                     .name = "hexagonv67",
                     .llvm_name = "hexagonv67",
                     .features = featureSet(&[_]Feature{
                                      .compound,
                                      .duplex,
                                      .mem_noshuf,
                                      .memops,
                                      .nvj,
                                      .nvs,
                                      .packets,
                                      .small_data,
                                      .v5,
                                      .v55,
                                      .v60,
                                      .v62,
                                      .v65,
                                      .v66,
                                      .v67,
                     }),
    };
    pub const hexagonv67t = CpuModel{
                     .name = "hexagonv67t",
                     .llvm_name = "hexagonv67t",
                     .features = featureSet(&[_]Feature{
                                      .audio,
                                      .compound,
                                      .mem_noshuf,
                                      .memops,
                                      .nvs,
                                      .packets,
                                      .small_data,
                                      .tinycore,
                                      .v5,
                                      .v55,
                                      .v60,
                                      .v62,
                                      .v65,
                                      .v66,
                                      .v67,
                     }),
    };
};
